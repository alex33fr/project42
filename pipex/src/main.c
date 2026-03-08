/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:15:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/08 01:35:32 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_wait_child(t_pipex *pipex)
{
    int status;

    waitpid(pipex->pid1, NULL, 0);
    waitpid(pipex->pid2, &status, 0);
    return (status >> 8);
}

static void	ft_try_open_create(t_pipex *pipex, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror(av[1]);
		pipex->infile = open("/dev/null", O_RDONLY);
	}
	pipex->outfile = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->outfile < 0)
		perror(av[4]);
}

static void	ft_fork_process(t_pipex *pipex, char **av, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		ft_child1(pipex, av[2], envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		ft_child2(pipex, av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int	status;

	ft_bzero(&pipex, sizeof(t_pipex));
	if (ac == 5)
	{
		ft_try_open_create(&pipex, av);
		if (pipe(pipex.pipefd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		ft_fork_process(&pipex, av, envp);
		ft_close_fd(pipex.pipefd[0],pipex.pipefd[1]);
		status = ft_wait_child(&pipex);
		ft_close_files(pipex.infile, pipex.outfile);
		return (status);
	}
	else
		ft_putstr_fd("Error : bad args!", 2);
	return (1);
}
