/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:24:33 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/21 18:04:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	error_pipex(char **arr, int fd)
{
	if (arr != NULL)
		free_array(arr, NULL);
	if (fd > 0)
		close(fd);
	if(errno == 0)
		exit(12);
	perror(strerror(errno));
	exit(errno);
} */

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	process_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	file_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

/* void	free_array(char **array, char *path)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(NULL);
		i++;
	}
	free(array);
	if (path != NULL)
		free(path);
} */

/*char	*make_path(char *path, char *cmd)
{
	char	*path_cmd;

	path_cmd = malloc(ft_strlen(cmd) + ft_strlen(path) + 2);
	if (path_cmd != NULL)
		return (NULL);
	ft_bzero(path_cmd, ft_strlen(cmd) + ft_strlen(path) + 2);
	ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
	ft_strlcat(path_cmd, "/", ft_strlen(path) + 2);
	ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 2);
	return (path);
}

char	*write_path(char *cmd, char **path)
{
	char	*path_cmd;

	if (access(cmd, F_OK) == -1)
	{
		while (*path != NULL)
		{
			path_cmd = make_path(*path, cmd);
			if (path_cmd == NULL)
				return (NULL);
			if (access(path_cmd, F_OK | W_OK) != -1)
				return (path_cmd);
			free(path_cmd);
			path++;
		}
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	}
	else
	{
		if (access(cmd, X_OK) == -1){
			error_pipex(path, 0);
			ft_putstr_fd("\033[31mError function write_path\n\e[0m", 2);}
		path_cmd = ft_substr(cmd, 0, ft_strlen(cmd));
	}
	return (path_cmd);
}*/

void	cmd_not_found(char *cmd)
{
	ft_printf("command not found: %s\n", cmd);
	errno = EKEYEXPIRED;
}

/*char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}*/