/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 00:52:26 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		game->p_dir = NORTH;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->p_dir = SOUTH;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		game->p_dir = WEST;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->p_dir = EAST;
	else
		return (0);
	if (game->p_dir == NORTH)
		ft_try_move(game, -1, 0);
	else if (game->p_dir == SOUTH)
		ft_try_move(game, 1, 0);
	else if (game->p_dir == WEST)
		ft_try_move(game, 0, -1);
	else if (game->p_dir == EAST)
		ft_try_move(game, 0, 1);
	return (0);
}
