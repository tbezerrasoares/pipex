/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:52:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/21 18:18:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex pipex, char **argv)
{
	dup2(pipex.tube[1], STDOUT_FILENO);
	close(pipex.tube[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		process_free(&pipex);
		msg_error(ERR_CMD);
		exit(1);	
	}
	execve(pipex.cmd, pipex.cmd_args, environ);
}

void	parent_process(t_pipex pipex, char **argv)
{
	dup2(pipex.tube[0], STDIN_FILENO);
	close(pipex.tube[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		process_free(&pipex);
		msg_error(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, environ);
}

void	pipex_fork(t_pipex *pipex, char **argv)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		process_free(pipex);
		msg_error(ERR_FORK);
		exit(1);
	}
	else if (pipex->pid == 0)
		child_process(*pipex, argv);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		parent_process(*pipex, argv);
	close_pipes(pipex);
	waitpid(pipex->pid, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	file_free(pipex);
}

int main(int argc, char **argv)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd(ERR_INPUT, 2);
		exit(1);
	}
	pipex.infile = open(argv[1], O_RDONLY, 0777);
	if (pipex.infile == -1)
		msg_error(ERR_INFILE);
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.outfile == -1)
		msg_error(ERR_OUTFILE);
	if (pipe(pipex.tube) == -1)
		msg_error(ERR_PIPE);
	pipex.path = find_path(environ);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	pipex_fork(&pipex, argv);
	return (0);
}
/* void child_process(char **argv, int *p_fd)
{
	int		fd;
	char *filename = "/bin/ls";
	char *ar[] = { "ls", "-l", NULL };
	char *path[] = { "PATH=/usr/bin", NULL };
		
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Error: File not found\n", 2);
		exit(1);
	}
	dup2(p_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(p_fd[0]);
	execve(filename, ar, path);
}

void parent_process(char **argv, int *p_fd)
{
	int		fd;
	char *filename = "/bin/wc";
	char *ar[] = { "wc", "-l", NULL };
	char *path[] = { "PATH=/usr/bin", NULL };
	
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Error: File not found\n", 2);
		exit(1);
	}	
	dup2(p_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(p_fd[1]);
	execve(filename, ar, path);
}

int main(int argc, char **argv)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(1);
	}
	if (pipe(p_fd) == -1)
	{
		ft_putstr_fd("Error: Pipe failed\n", 2);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error: Fork failed\n", 2);
		exit(1);
	}
	if (pid == 0)
		child_process(argv, p_fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, p_fd);
} */

/* int main() {
	char *cmd = "ls";
	char **path = get_path(environ);
	char *result = find_path(cmd, environ);
	//int i;
	printf("Path command: %s\n", result);
	for (i = 0; path[i] != NULL; i++)
		printf("path[%d] = %s\n", i, path[i]);
	free(result);
	free(cmd);
	free_ft_split(path);
	return 0;
} */


/* int main() {
	char *filename = "/bin/ls";
	char *argv[] = { "ls", "-l", NULL };
	char *envp[] = { "PATH=/usr/bin", NULL };

	ft_printf("Executing %s\n", filename);
	ft_printf("With arguments:%s\n", argv[0]);
	ft_printf("With arguments:%s\n", argv[1]);
	ft_printf("With environment:%s\n", envp[0]);
	execve(filename, argv, envp);

	char *filename2 = "/bin/pwd";
	char *argv2[] = { "pwd", NULL };
	char *envp2[] = { "PATH=/usr/bin", NULL };

	execve(filename2, argv2, envp2);

	return 0;
} */