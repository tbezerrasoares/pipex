/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/16 19:31:21 by codespace        ###   ########.fr       */
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
#include "./libft/ft_printf.h"

extern char	**environ;

void	error_pipex(char **arr, int fd);
void	free_array(char **array, char *path);
void	status_outfile(char **argv, int argc);
void	**status_split(char *cmd, char **arr);
char	**get_path(char **environ);
static char	*make_payh(char *path, char *cmd);
char	*write_path(char *cmd, char **path);