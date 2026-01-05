/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:41:30 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/05 16:43:08 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
typedef struct s_game
{
    void	*mlx;
    void	*win;
    void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
    char	**map;
    int		map_width;
    int		map_height;
    int		p_x;
    int		p_y;
    int		coins;
    int		moves;
}				t_game;
char **ft_prepare_map(void);
int ft_checker_map(char **map);
int ft_map_height(char **map);
int ft_map_width(char *line);
void ft_free_map(char **map);
int ft_has_valid_chars(char **map);
void ft_init_game(t_game *game);
void ft_find_player(t_game *game);
void ft_tracer_map(t_game *game);
#endif