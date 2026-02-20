/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 01:03:40 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_handle_tile(t_game *g, int nx, int ny)
{
	if (g->map[nx][ny] == 'C')
	{
		g->picked_pickaxes++;
		g->map[nx][ny] = '0';
	}
	if (g->map[nx][ny] == 'E')
	{
		if (g->picked_pickaxes > 0
			&& g->used_pickaxes < g->total_pickaxes)
		{
			g->picked_pickaxes--;
			g->used_pickaxes++;
			g->gate_state = (g->used_pickaxes * 4)
				/ g->total_pickaxes;
			if (g->gate_state < 1)
				g->gate_state = 1;
			if (g->gate_state > 4)
				g->gate_state = 4;
		}
		else if (g->used_pickaxes == g->total_pickaxes
			&& g->gate_state == 4)
			ft_win(g);
	}
}

void	ft_try_move(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->p_x + dx;
	ny = g->p_y + dy;
	if (nx < 0 || ny < 0
		|| nx >= g->map_height
		|| ny >= g->map_width)
		return ;
	if (g->map[nx][ny] == '1')
		return ;
	ft_handle_tile(g, nx, ny);
	g->p_x = nx;
	g->p_y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	mlx_clear_window(g->mlx, g->win);
	ft_tracer_map(g);
}
