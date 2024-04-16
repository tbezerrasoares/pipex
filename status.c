/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:13:31 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/16 11:23:45 by tbezerra         ###   ########.fr       */
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

void	**status_split(char *cmd, char **arr)
{
	char	**part;

	if(access(cmd, F_OK) == -1)
		handle_erro
}