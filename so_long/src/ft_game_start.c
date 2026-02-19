/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/19 16:04:53 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_game *game, char *map_path)
{
	game->map = ft_prepare_map(map_path);
	if (!game->map)
		ft_exit(game, "Error 2\nInvalid map");
	if (!ft_has_valid_chars(game->map)
    	|| !ft_is_rectangular(game->map)
    	|| !ft_is_closed_by_walls(game->map)
    	|| !ft_has_valid_elements(game->map)
    	|| !ft_map_has_valid_path(game->map))
		ft_exit(game, "Error 3\nInvalid map");
	game->map_height = ft_map_height(game->map);
	game->map_width = ft_map_width(game->map[0]);
}

static void init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        ft_exit(game, "Error\nMLX failed");
    game->win = mlx_new_window(game->mlx,
            game->map_width * 32,
            game->map_height * 32,
            "so_long");
    if (!game->win)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        ft_exit(game, "Error\nWindow failed");
    }
}

static void	init_entities(t_game *game)
{
	ft_init_game(game);
	ft_init_player(game);
	ft_init_pickaxes(game);
	game->gate_state = 0;
}

static void	init_hooks(t_game *game)
{
	mlx_key_hook(game->win, ft_key_input, game);
	mlx_hook(game->win, 17, 0, ft_close, game);
}

void	ft_game_start(t_game *game, char *map_path)
{
	init_map(game, map_path);
	init_mlx(game);
	init_entities(game);
	ft_tracer_map(game);
	init_hooks(game);
	mlx_loop(game->mlx);
}
