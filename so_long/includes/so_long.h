/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:41:30 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/29 07:16:48 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
void ft_prepare_map(void);
int ft_checker_map(char **map);
int ft_map_height(char **map);
int ft_map_width(char *line);
void ft_free_map(char **map);
int ft_has_valid_chars(char **map);
#endif