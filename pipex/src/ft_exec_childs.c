/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_childs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:03 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/10 12:13:11 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex *pipex, char *cmd, char **envp)
{
	char	**tab;
	char	*path;

	if (pipex->infile < 0)
        exit(1);
    dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	ft_close_fd(pipex->pipefd[0], pipex->pipefd[1]);
	tab = ft_split(cmd, ' ');
	if (!tab)
	{
		ft_close_files(pipex->infile, pipex->outfile);
		exit(1);
	}
	path = ft_find_path(tab[0], envp);
	if (!path)
	{
		ft_free_pipex_tab(tab);
		exit(127);
	}
	execve(path, tab, envp);
	perror(tab[0]);
	free(path);
	ft_free_pipex_tab(tab);
	ft_close_files(pipex->infile, pipex->outfile);
	exit(1);
}

void	ft_child2(t_pipex *pipex, char *cmd, char **envp)
{
	char	**tab;
	char	*path;

	if (pipex->outfile < 0)
		exit(1);
	dup2(pipex->pipefd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	ft_close_fd(pipex->pipefd[0], pipex->pipefd[1]);
	tab = ft_split(cmd, ' ');
	if (!tab)
	{
		ft_close_files(pipex->infile, pipex->outfile);
		exit(1);
	}
	path = ft_find_path(tab[0], envp);
	if (!path)
	{
		ft_free_pipex_tab(tab);
		ft_close_files(pipex->infile, pipex->outfile);
		exit(127);
	}
	execve(path, tab, envp);
	perror(tab[0]);
	free(path);
	ft_free_pipex_tab(tab);
	ft_close_files(pipex->infile, pipex->outfile);
	exit(1);
}
