/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:43:10 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/05 17:31:57 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *g)
{
	int	w;
	int	h;

	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
	g->img_coin = mlx_xpm_file_to_image(g->mlx, "textures/coin.xpm", &w, &h);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "textures/character_left.xpm", &w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
}