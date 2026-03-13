/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_childs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:03 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/10 15:47:30 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_child(char *path, char **tab, char **envp)
{
	execve(path, tab, envp);
	perror(tab[0]);
	free(path);
	ft_free_pipex_tab(tab);
}

static char	*ft_get_path(char **tab, char **envp)
{
	char	*path;

	path = ft_find_path(tab[0], envp);
	if (!path)
	{
		ft_putstr_fd(tab[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_pipex_tab(tab);
		exit(127);
	}
	return (path);
}

void	ft_child1(t_pipex *pipex, char *cmd, char **envp)
{
	char	**tab;
	char	*path;

	if (pipex->infile < 0)
	{
		ft_close(pipex->pipefd[0], pipex->pipefd[1]);
		close(pipex->outfile);
		exit(1);
	}
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	ft_close(pipex->pipefd[0], pipex->pipefd[1]);
	close(pipex->outfile);
	tab = ft_split(cmd, ' ');
	if (!tab)
		exit(1);
	path = ft_get_path(tab, envp);
	ft_exec_child(path, tab, envp);
	exit(1);
}

void	ft_child2(t_pipex *pipex, char *cmd, char **envp)
{
	char	**tab;
	char	*path;

	if (pipex->outfile < 0)
	{
		ft_close(pipex->pipefd[0], pipex->pipefd[1]);
		close(pipex->infile);
		exit(1);
	}
	dup2(pipex->pipefd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	ft_close(pipex->pipefd[0], pipex->pipefd[1]);
	close(pipex->infile);
	tab = ft_split(cmd, ' ');
	if (!tab)
		exit(1);
	path = ft_get_path(tab, envp);
	ft_exec_child(path, tab, envp);
	exit(1);
}
