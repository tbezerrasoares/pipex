/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/19 18:22:43 by codespace        ###   ########.fr       */
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

void		error_pipex(char **arr, int fd);
void		free_array(char **array, char *path);
void		status_outfile(char **argv, int argc);
char		**status_split(char *cmd, char **arr);
char		**get_path(char **environ);
char		*make_payh(char *path, char *cmd);
char		*write_path(char *cmd, char **path);
void		cmd_not_found(char *cmd);