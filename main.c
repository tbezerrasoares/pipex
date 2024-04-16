/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:52:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/04/16 11:01:20 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int		fd;
	char	**cmd_path;

	errno = 0;
	if (argc < 5)
	{
		perror("Error in argument number");
		errno = EIO;
		exit(errno);
	}
	status_outfile(argv, --argc);
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		fd = open(argv[argc])
	}
}