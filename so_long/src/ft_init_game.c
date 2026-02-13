/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:43:10 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/13 15:58:31 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_img(t_game *game, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, w, h);
	if (!img)
		ft_exit(game, "Error\nFailed to load sprite");
	return (img);
}

void	ft_init_game(t_game *game)
{
	int	w;
	int	h;

	game->total_pickaxes = 0;
	game->used_pickaxes = 0;
	game->gate_state = 1;

	game->img_wall = load_img(game, "sprite/wall/wall.xpm", &w, &h);
	game->img_floor = load_img(game, "sprite/floor/floor.xpm", &w, &h);
	game->img_pickaxe = load_img(game, "sprite/loot/pickaxe.xpm", &w, &h);

	game->img_p_south = load_img(game, "sprite/character/south.xpm", &w, &h);
	game->img_p_north = load_img(game, "sprite/character/north.xpm", &w, &h);
	game->img_p_west = load_img(game, "sprite/character/west.xpm", &w, &h);
	game->img_p_east = load_img(game, "sprite/character/east.xpm", &w, &h);

	game->img_gate_1 = load_img(game, "sprite/gate/gate_1.xpm", &w, &h);
	game->img_gate_2 = load_img(game, "sprite/gate/gate_2.xpm", &w, &h);
	game->img_gate_3 = load_img(game, "sprite/gate/gate_3.xpm", &w, &h);
	game->img_gate_4 = load_img(game, "sprite/gate/gate_4.xpm", &w, &h);

	game->p_dir = SOUTH;
}
