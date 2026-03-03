/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:15:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/02 11:17:50 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fds(t_pipex *px)
{
}

static void	wait_children(t_pipex *px)
{
}

int	main(int ac, char **av, char **envp)
{
	int	av_1;
	int	av_4;
	int	pipefd[2];

	if (ac == 5)
	{
		av_1 = open(av[1], O_RDONLY);
		if (av_1 < 0)
			perror("Error, file not found");
		av_4 = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (av_4 < 0)
			perror("Error, file not found");
	}
	else
	{
		ft_printf("Bad Arg!");
	}
	return (0);
}
