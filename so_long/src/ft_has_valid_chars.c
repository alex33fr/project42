/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:15:11 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/29 07:13:45 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_has_valid_p(char **map)
{
    int x;
    int y;
    int count_p;

    x = -1;
    count_p = 0;
    while (map[++x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == 'P')
                count_p++;
            y++;
        }
    }
    if (count_p != 1)
        return (0);
    return (1);
}

static int	ft_has_valid_e(char **map)
{
    int x;
    int y;
    int count_e;

    x = -1;
    count_e = 0;
    while (map[++x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == 'E')
                count_e++;
            y++;
        }
    }
    if (count_e != 1)
        return (0);
    return (1);
}
static int	ft_has_valid_c(char **map)
{
    int x;
    int y;
    int count_c;

    x = -1;
    count_c = 0;
    while (map[++x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == 'C')
                count_c++;
            y++;
        }
    }
    if (count_c < 1)
        return (0);
    return (1);
}
static int	ft_has_valid_elements(char **map)
{
    if (ft_has_valid_p(map) == 0)
        return (0);
    if (ft_has_valid_e(map) == 0)
        return (0);
    if (ft_has_valid_c(map) == 0)
        return (0);
    return (1);
}
int	ft_has_valid_chars(char **map)
{
    int	x;
    int	y;

    if (!map)
        return (0);
    x = -1;
    while (map[++x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] != '0' && map[x][y] != '1' &&
                map[x][y] != 'P' && map[x][y] != 'E' &&
                 map[x][y] != 'C')
                return (0);
            y++;
        }
    }
    if (ft_has_valid_elements(map) == 0)
        return (0);
    return (1);
}
