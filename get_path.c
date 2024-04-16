/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:06:29 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 16:32:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **environ)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	path = NULL;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			temp = ft_substr(environ[i], 5, ft_strlen(environ[i] + 5));
			path = ft_split(temp, ':');
			free(temp);
		}
		i++;
	}
	return (path);
}