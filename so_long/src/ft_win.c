/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/19 15:57:52 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_win(t_game *game)
{
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);
    ft_printf("You win!\n");
    ft_close(game);
}
