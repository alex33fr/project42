/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:25 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/10 11:28:18 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path_splitted(char **envp)
{
	char	**envp_s;
	int		i;
	int		len;

	i = 0;
	len = 5;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", len) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (NULL);
	envp_s = ft_split(envp[i] + len, ':');
	if (!envp_s)
		return (NULL);
	return (envp_s);
}

static char	*ft_build_full_path(char *path, char *cmd)
{
	char	*tab;
	char	*full_path;

	if (!path || !cmd)
		return (NULL);
	tab = ft_strjoin(path, "/");
	if (!tab)
		return (NULL);
	full_path = ft_strjoin(tab, cmd);
	free(tab);
	return (full_path);
}

static char	*ft_search_path(char **paths, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_build_full_path(paths[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_get_path_splitted(envp);
	if (!paths)
		exit(127);
	path = ft_search_path(paths, cmd);
	ft_free_pipex_tab(paths);
	return (path);
}
