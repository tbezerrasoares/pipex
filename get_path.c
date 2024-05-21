/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:06:29 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 18:01:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* char	**get_path(char **environ)
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
			break;
		}
		i++;
	}
	return (path);
}

static char	*make_path(char *path, char *cmd)
{
	char	*path_cmd;

	path_cmd = ft_calloc((ft_strlen(cmd) + ft_strlen(path) + 2), sizeof(char));
	if (path_cmd == NULL)
		return (NULL);
	ft_strlcat(path_cmd, path, ft_strlen(path) + 1);
	ft_strlcat(path_cmd, "/", ft_strlen(path) + 2);
	ft_strlcat(path_cmd, cmd, ft_strlen(path) + ft_strlen(cmd) + 2);
	return (path_cmd);
}

char	*write_path(char *cmd, char **path)
{
	char	*path_cmd;

	path = get_path(environ);
	if (access(cmd, F_OK) == -1)
	{
		while (*path != NULL)
		{
			path_cmd = make_path(*path, cmd);
			if (path_cmd == NULL)
				return (NULL);
			if (access(path_cmd, F_OK | X_OK) != -1)
				return (path_cmd);
			free(path_cmd);
			path++;
		}
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	}
	else
	{
		if (access(cmd, X_OK) == -1)
			error_pipex(path, 0);
		path_cmd = ft_substr(cmd, 0, ft_strlen(cmd));
	}
	return (path_cmd);
} */

/* char	*find_path(char *cmd, char **envp)
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
} */

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}