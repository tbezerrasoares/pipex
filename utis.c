/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:24:33 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/16 11:32:57 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipex(char **arr, int fd)
{
	if (arr != NULL)
		free_array(arr, NULL);
	if (fd > 0)
		close(fd);
	if(errno == 0)
		exit(12);
	perror(strerror(errno));
	exit(errno);
}

void	free_array(char **array, char *path)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(NULL);
		i++;
	}
	free[array];
	if (path != NULL)
		free[path];
}