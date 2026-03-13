/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:50 by aprivalo          #+#    #+#             */
/*   Updated: 2026/03/13 10:25:31 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipex_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_close(int in1, int in2)
{
	if (in1 >= 0)
		close(in1);
	if (in2 >= 0)
		close(in2);
}

int	ft_wait_child(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, &status, 0);
	return (status >> 8);
}
