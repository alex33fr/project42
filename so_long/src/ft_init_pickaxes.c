/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pickaxes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/29 15:40:38 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_pickaxes(t_game *game)
{
	int	x;
	int	y;

	game->total_pickaxes = 0;
	game->picked_pickaxes = 0;
	game->used_pickaxes = 0;
	game->gate_state = 1;
	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'C')
				game->total_pickaxes++;
			y++;
		}
		x++;
	}
}
