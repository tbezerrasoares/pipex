/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:52:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/19 17:50:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_fd(int *fd, int mode, char **cmd_path)
{
	if (mode == 0)
	{
		if (dup2(fd[1], 1) == -1 || dup2(fd[0], 0) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			error_pipex(cmd_path, 0);
		}
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		error_pipex(cmd_path, 0);
	}
}

void	dad_process(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;
	int		set;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
		error_pipex(cmd_path, fd[0]);
	waitpid(-1, &set, WNOHANG);
	pipe_fd(fd, 0, cmd_path);
	cmd = status_split(argv[argc - 1], cmd_path);
	if (cmd == NULL)
		error_pipex(cmd_path, 0);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found(cmd[0]);
		else
			perror(strerror(errno));
		free_array(cmd, path);
		exit(errno);
	}
}

void	son_process(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		error_pipex(cmd_path, fd[1]);
	pipe_fd(fd, 0, cmd_path);
	cmd = status_split(argv[2], cmd_path);
	if (cmd == NULL)
		error_pipex(cmd_path, 0);
	path = write_path(cmd[0], cmd_path);
	free_array(cmd_path, NULL);
	if (execve(path, cmd, environ) == -1)
	{
		if (errno == ENOENT || errno == EKEYEXPIRED)
			cmd_not_found(cmd[0]);
		else
			perror(strerror(errno));
		free_array(cmd, path);
	}
	
}

int	pipe_fork(int argc, char **argv, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		error_pipex(NULL, 0);
	id = fork();
	if (id == -1)
	{
		pipe_fd(fd, 1, cmd_path);
		error_pipex(NULL, 0);
	}
	else if (id == 0)
		son_process(fd, argv, cmd_path);
	else
		dad_process(fd, argv, argc, cmd_path);
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError in argument number\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	status_outfile(argv, --argc);
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		fd = open(argv[argc], O_WRONLY, O_CREAT, 0777);
		if (fd == -1)
			error_pipex(NULL, 0);
		write(fd, "0\n", 2);
		perror(strerror(errno));
		exit(0);
	}
	cmd_path = get_path(environ);
	return (pipe_fork(argc, argv, cmd_path));
}