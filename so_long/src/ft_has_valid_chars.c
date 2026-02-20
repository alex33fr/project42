/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:15:11 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 02:08:31 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_has_valid_p(char **map)
{
	int	x;
	int	y;
	int	count_p;

	x = 0;
	count_p = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				count_p++;
			y++;
		}
		x++;
	}
	if (count_p != 1)
		return (0);
	return (1);
}

static int	ft_has_valid_e(char **map)
{
	int	x;
	int	y;
	int	count_e;

	x = 0;
	count_e = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
				count_e++;
			y++;
		}
		x++;
	}
	if (count_e != 1)
		return (0);
	return (1);
}

static int	ft_has_valid_c(char **map)
{
	int	x;
	int	y;
	int	count_c;

	x = 0;
	count_c = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count_c++;
			y++;
		}
		x++;
	}
	if (count_c < 1)
		return (0);
	return (1);
}

int	ft_has_valid_chars(char **map)
{
	if (!ft_has_valid_p(map))
		return (0);
	if (!ft_has_valid_e(map))
		return (0);
	if (!ft_has_valid_c(map))
		return (0);
	return (1);
}
