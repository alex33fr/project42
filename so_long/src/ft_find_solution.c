/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:15:11 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/29 16:45:51 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_dup_map(char **map)
{
	int		height;
	int		i;
	char	**tab_dup;

	height = ft_map_height(map);
	tab_dup = (char **)malloc(sizeof(char *) * (height + 1));
	if (!tab_dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		tab_dup[i] = ft_strdup(map[i]);
		if (!tab_dup[i])
		{
			ft_free_map(tab_dup);
			return (NULL);
		}
		i++;
	}
	tab_dup[i] = NULL;
	return (tab_dup);
}

static int	ft_find_player(char **map, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				*p_x = x;
				*p_y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

static void	ft_flood(char **m, int x, int y)
{
	if (x < 0 || y < 0 || !m[x] || !m[x][y])
		return ;
	if (m[x][y] == '1' || m[x][y] == 'V')
		return ;
	m[x][y] = 'V';
	ft_flood(m, x + 1, y);
	ft_flood(m, x - 1, y);
	ft_flood(m, x, y + 1);
	ft_flood(m, x, y - 1);
}

static int	ft_all_reachable(char **flooded, char **init)
{
	int	x;
	int	y;

	x = 0;
	while (init[x])
	{
		y = 0;
		while (init[x][y])
		{
			if (init[x][y] == 'C' && flooded[x][y] != 'V')
				return (0);
			if (init[x][y] == 'E' && flooded[x][y] != 'V')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_map_has_valid_path(char **map)
{
	char	**dup;
	int		x;
	int		y;
	int		valid;

	dup = ft_dup_map(map);
	if (!dup)
		return (0);
	if (!ft_find_player(map, &x, &y))
	{
		ft_free_map(dup);
		return (0);
	}
	ft_flood(dup, x, y);
	valid = ft_all_reachable(dup, map);
	ft_free_map(dup);
	if (!valid)
		return (0);
	return (1);
}
