/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:21:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/17 10:22:43 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_ft_split(char **split)
{
	int		i;

	i = 0;
	if (split)
	{
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
