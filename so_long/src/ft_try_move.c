/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/29 15:41:14 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_try_move(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->p_x + dx;
	ny = g->p_y + dy;
	if (g->map[nx][ny] == '1')
		return ;
	if (g->map[nx][ny] == 'C')
	{
		g->picked_pickaxes++;
		g->map[nx][ny] = '0';
	}
	if (g->map[nx][ny] == 'E')
	{
		if (g->picked_pickaxes > 0 && g->used_pickaxes < g->total_pickaxes)
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
		else if (g->used_pickaxes == g->total_pickaxes && g->gate_state == 4)
			ft_win(g);
	}
	g->p_x = nx;
	g->p_y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	mlx_clear_window(g->mlx, g->win);
	ft_tracer_map(g);
}
