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

int	main(int argc, char **argv)
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
