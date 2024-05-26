/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/21 18:05:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "./libft/libft.h"

extern char	**environ;

#define ERR_INFILE "Infile"
#define ERR_OUTFILE "Outfile"
#define ERR_INPUT "Invalid number of arguments.\n"
#define ERR_PIPE "Pipe"
#define ERR_FORK "Fork"
#define ERR_CMD "Command not found\n"

typedef struct pipex
{
	pid_t	pid;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd_args;
	char	*path;
	char	*cmd;
}	t_pipex;

char	*find_path(char **envp);
void	close_pipes(t_pipex *pipex);
char	*get_cmd(char **paths, char *cmd);
void	process_free(t_pipex *pipex);
void	file_free(t_pipex *pipex);
void	msg_error(char *err);
