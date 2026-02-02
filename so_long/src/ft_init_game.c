/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:43:10 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/29 15:39:23 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	int	w;
	int	h;

	game->total_pickaxes = 0;
	game->used_pickaxes = 0;
	game->gate_state = 1;
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"sprite/wall/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"sprite/floor/floor.xpm", &w, &h);
	game->img_pickaxe = mlx_xpm_file_to_image(game->mlx,
			"sprite/loot/pickaxe.xpm", &w, &h);
	game->img_p_south = mlx_xpm_file_to_image(game->mlx,
			"sprite/character/south.xpm", &w, &h);
	game->img_p_north = mlx_xpm_file_to_image(game->mlx,
			"sprite/character/north.xpm", &w, &h);
	game->img_p_west = mlx_xpm_file_to_image(game->mlx,
			"sprite/character/west.xpm", &w, &h);
	game->img_p_east = mlx_xpm_file_to_image(game->mlx,
			"sprite/character/east.xpm", &w, &h);
	game->img_gate_1 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gate/gate_1.xpm", &w, &h);
	game->img_gate_2 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gate/gate_2.xpm", &w, &h);
	game->img_gate_3 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gate/gate_3.xpm", &w, &h);
	game->img_gate_4 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gate/gate_4.xpm", &w, &h);
	game->p_dir = DIR_SOUTH;
}
