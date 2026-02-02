/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:15:11 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/26 16:16:45 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (g->map[x])
	{
		y = 0;
		while (g->map[x][y])
		{
			if (g->map[x][y] == 'P')
			{
				g->p_x = x;
				g->p_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
