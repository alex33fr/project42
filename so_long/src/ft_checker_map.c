/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:15:11 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 01:42:03 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangular(char **map)
{
	int	x;
	int	width;

	if (!map || !map[0])
		return (0);
	width = ft_map_width(map[0]);
	if (width == 0)
		return (0);
	x = 0;
	while (map[x])
	{
		if (ft_map_width(map[x]) != width)
			return (0);
		x++;
	}
	return (1);
}

int	ft_is_closed_by_walls(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	height = ft_map_height(map);
	width = ft_map_width(map[0]);
	y = 0;
	x = 0;
	while (y < width)
	{
		if (map[0][y] != '1' || map[height - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < height)
	{
		if (map[x][0] != '1' || map[x][width - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_has_pickaxe(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
