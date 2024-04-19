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

static int	func_fork(int argc, char **argv, char **cmd_path);
static void	son_func(int *fd, char **argv, char **cmd_path);
static void	dad_func(int *fd, char **argv, int argc, char **cmd_path);

int main(int argc, char **argv)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	if (argc < 5)
	{
		perror("Error in argument number");
		errno = EIO;
		exit(errno);
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
	return (func_fork(argc, argv, cmd_path));
}

static void	func_fd(int *fd, int mode, char **cmd_path)
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

static void	dad_func(int *fd, char **argv, int argc, char **cmd_path)
{
	char	*path;
	char	**cmd;
	int		set;

	close(fd[1]);
	fd[1] = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (fd[1] == -1)
		error_pipex(cmd_path, fd[0]);
	waitpid(-1, &set, WNOHANG);
	func_fd(fd, 0, cmd_path);
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

static void	son_func(int *fd, char **argv, char **cmd_path)
{
	char	*path;
	char	**cmd;

	close(fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_pipex(cmd_path, fd[1]);
	func_fd(fd, 0, cmd_path);
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

static int	func_fork(int argc, char **argv, char **cmd_path)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		error_pipex(NULL, 0);
	id = fork();
	if (id == -1)
	{
		func_fd(fd, 1, cmd_path);
		error_pipex(NULL, 0);
	}
	else if (id = 0)
		son_func(fd, argv, cmd_path);
	else
		dad_func(fd, argv, argc, cmd_path);
	return (0);
}
