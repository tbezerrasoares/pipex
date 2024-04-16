/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:13:31 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/16 13:51:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	status_outfile(char **argv, int argc)
{
	if (access(argv[argc], F_OK) == 0)
	{
		if (unlink(argv[argc]) == -1)
		{
			perror(strerror(errno));
			exit(1);
		}
	}
}

char	**status_split(char *cmd, char **arr)
{
	char	**part;

	if(access(cmd, F_OK) == -1)
		part = ft_split(cmd, ' ');
	else
	{
		if (access(cmd, X_OK) == 1)
			error_pipex(arr, 0);
		part = malloc(sizeof(char *) * 2);
		*part = ft_substr(cmd, 0, ft_strlen(cmd));
		*(part + 1) = NULL;
	}
	return (part);
}