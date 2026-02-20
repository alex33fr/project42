/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:41:30 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/20 01:43:51 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define SOUTH 0
# define NORTH 1
# define WEST 2
# define EAST 3

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_p_north;
	void	*img_p_south;
	void	*img_p_west;
	void	*img_p_east;
	void	*img_gate_1;
	void	*img_gate_2;
	void	*img_gate_3;
	void	*img_gate_4;
	void	*img_pickaxe;
	char	**map;
	int		map_width;
	int		map_height;
	int		p_x;
	int		p_y;
	int		p_dir;
	int		total_pickaxes;
	int		picked_pickaxes;
	int		used_pickaxes;
	int		gate_state;
	int		moves;
}	t_game;
char	**ft_prepare_map(char *path);
void	ft_free_map(char **map);
int		ft_map_height(char **map);
int		ft_map_width(char *line);
int		ft_has_valid_chars(char **map);
int		ft_is_rectangular(char **map);
int		ft_is_closed_by_walls(char **map);
int		ft_map_has_valid_path(char **map);
void	ft_game_start(t_game *game, char *map_path);
void	ft_init_game(t_game *game);
void	ft_init_player(t_game *game);
void	ft_init_pickaxes(t_game *game);
void	ft_tracer_map(t_game *game);
void	*ft_gate_img(t_game *game);
void	*ft_player_img(t_game *game);
void	ft_try_move(t_game *game, int dx, int dy);
int		ft_key_input(int keycode, t_game *game);
int		ft_close(t_game *game);
void	ft_win(t_game *game);
void	ft_exit(t_game *game, char *msg);
int		ft_error(char *str);
int		ft_has_pickaxe(char **map);
int		ft_has_ber_extension(char *filename);
int		ft_checker_map(char **map);
#endif
