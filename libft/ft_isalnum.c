/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2023/10/16 12:37:42 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg >= 48 && arg <= 57) || (arg >= 65 && arg <= 90)
		|| (arg >= 97 && arg <= 122))
		return (1);
	else
		return (0);
}
