/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:15:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/13 10:22:56 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_open_infile(t_pipex *pipex, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		perror(av[1]);
}

static void	ft_open_outfile(t_pipex *pipex, char **av)
{
	pipex->outfile = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->outfile < 0)
		perror(av[4]);
}

static void	ft_open_process(t_pipex *pipex, char **av)
{
	ft_open_infile(pipex, av);
	ft_open_outfile(pipex, av);
	if (pipe(pipex->pipefd) == -1)
	{
		perror("pipe");
		ft_close(pipex->infile, pipex->outfile);
		exit(1);
	}
}

static void	ft_fork_process(t_pipex *pipex, char **av, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pipex->pid1 == 0)
		ft_child1(pipex, av[2], envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pipex->pid2 == 0)
		ft_child2(pipex, av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		status;

	ft_bzero(&pipex, sizeof(t_pipex));
	if (ac == 5)
	{
		ft_open_process(&pipex, av);
		ft_fork_process(&pipex, av, envp);
		ft_close(pipex.pipefd[0], pipex.pipefd[1]);
		status = ft_wait_child(&pipex);
		ft_close(pipex.infile, pipex.outfile);
		return (status);
	}
	else
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	return (1);
}
