/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:55:32 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 00:49:12 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_player_img(t_game *g)
{
	if (g->p_dir == NORTH)
		return (g->img_p_north);
	else if (g->p_dir == WEST)
		return (g->img_p_west);
	else if (g->p_dir == EAST)
		return (g->img_p_east);
	else
		return (g->img_p_south);
}

static void	ft_draw_base(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[x][y];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_wall, y * 32, x * 32);
	else
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_floor, y * 32, x * 32);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img_pickaxe, y * 32, x * 32);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, ft_gate_img(game), y * 32, x * 32);
}

void	ft_tracer_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			ft_draw_base(game, x, y);
			if (game->p_x == x && game->p_y == y)
				mlx_put_image_to_window(game->mlx,
					game->win, ft_player_img(game),
					y * 32, x * 32);
			y++;
		}
		x++;
	}
}
