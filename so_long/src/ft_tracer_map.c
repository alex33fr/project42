/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:55:32 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/05 17:32:19 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_tracer_map(t_game *game)
{
    int	x;
    int	y;


    x = 0;
    printf("start trace\n");
    printf("size: w=%d h=%d\n", game->map_width, game->map_height);
    while (x < game->map_height)
    {
        y = 0;
        while (y < game->map_width)
        {
            if (game->map[x][y] == '1')
	            mlx_put_image_to_window(game->mlx, game->win, game->img_wall, y * 32, x * 32);
            else if (game->map[x][y] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, y * 32, x * 32);
            else if (game->map[x][y] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, y * 32, x * 32);
            else if (game->map[x][y] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, y * 32, x * 32);
            else if (game->map[x][y] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_coin, y * 32, x * 32);
            y++;
            printf("trace OK\n");
        }
        x++;
    }
}

