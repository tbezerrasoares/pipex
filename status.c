/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:13:31 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/21 15:57:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	status_outfile(char **argv, int argc)
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
	int		i;

	if(access(cmd, F_OK) == -1){
		part = ft_split(cmd, ' ');
		ft_printf("ok");}
	else
	{
		if (access(cmd, X_OK) == 1)
			error_pipex(arr, 0);
		ft_printf("erro");
		part = malloc(sizeof(char *) * 2);
		*part = ft_substr(cmd, 0, ft_strlen(cmd));
		*(part + 1) = NULL;
	}
	for (i = 0; part[i] != NULL; i++) {
        printf("part[%d] = %s\n", i, part[i]);
    }
	return (part);
} */

/*void	execute(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	//path = find_path(cmd[0], envp);
	path = write_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror(strerror(errno));
	}
	if (execve(path, cmd, envp) == -1)
		perror(strerror(errno));
}*/