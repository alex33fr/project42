/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/19 15:17:49 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_images(t_game *game)
{
	if (!game || !game->mlx)
        return ;
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_p_north)
		mlx_destroy_image(game->mlx, game->img_p_north);
	if (game->img_p_south)
		mlx_destroy_image(game->mlx, game->img_p_south);
	if (game->img_p_west)
		mlx_destroy_image(game->mlx, game->img_p_west);
	if (game->img_p_east)
		mlx_destroy_image(game->mlx, game->img_p_east);
	if (game->img_gate_1)
		mlx_destroy_image(game->mlx, game->img_gate_1);
	if (game->img_gate_2)
		mlx_destroy_image(game->mlx, game->img_gate_2);
	if (game->img_gate_3)
		mlx_destroy_image(game->mlx, game->img_gate_3);
	if (game->img_gate_4)
		mlx_destroy_image(game->mlx, game->img_gate_4);
	if (game->img_pickaxe)
		mlx_destroy_image(game->mlx, game->img_pickaxe);
}

int ft_close(t_game *game)
{
    if (!game)
        exit(0);
    ft_destroy_images(game);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if (game->map)
        ft_free_map(game->map);
    exit(0);
}

