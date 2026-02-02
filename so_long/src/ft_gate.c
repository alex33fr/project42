/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:55:32 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/28 22:28:12 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_gate_img(t_game *game)
{
	if (game->gate_state == 2)
		return (game->img_gate_2);
	if (game->gate_state == 3)
		return (game->img_gate_3);
	if (game->gate_state == 4)
		return (game->img_gate_4);
	return (game->img_gate_1);
}
