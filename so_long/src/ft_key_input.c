/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/28 17:45:46 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	ft_key_input(int keycode, t_game *game)
{
    (void)game;
	ft_printf("keycode = %d\n", keycode);
	return (0);
}
*/

int	ft_key_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->p_dir = DIR_NORTH;
		ft_try_move(game, -1, 0);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->p_dir = DIR_SOUTH;
		ft_try_move(game, 1, 0);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->p_dir = DIR_WEST;
		ft_try_move(game, 0, -1);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->p_dir = DIR_EAST;
		ft_try_move(game, 0, 1);
	}
	return (0);
}
