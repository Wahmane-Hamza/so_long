/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/15 10:36:27 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define ESC 65307
# define ON_DESTROY 17

typedef	struct s_enemy_path
{
	char	*enemy_back;
	char	*enemy_left;
	char	*enemy_front;
	char	*enemy_right;
}				t_enemy_path;

typedef	struct s_img_sides
{
	int	front;
	int	right;
	int enemy_front;
	int enemy_right;
	int	death;
	t_enemy_path	enemy_path;
}				s_img_side;


typedef struct s_img
{
	void		*img;
	int			img_width;
	int			img_height;
	char		*map_ground;
	char		*map_wall;
	char		*map_player;
	char		*map_coin;
	char		*house_open;
	char		*house_close;
	char		*enemy_front;
	char		*enemy_back;
	char		*enemy_right;
	char		*enemy_left;
	s_img_side	side;
}				t_img;

typedef struct l_elem_data
{
	int			p;
	int			e;
	int			c;
	int			m;
	int			house_open;
	int			p_posx;
	int			p_posy;
	int			num_move;
}				t_elem_data;

typedef struct t_map_data
{
	char		**array;
	int			map_x_len;
	int			map_y_len;
}				t_map_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_elem_data	elem;
	t_map_data	map;
}				t_mlx_data;

// Parsing
int				check_all(char **av, t_mlx_data *data);
int				flood_fill_bonus(t_mlx_data *data);
void			free_map(char **map);
int				error_exit(char *message, char *line, int fd, char **array);
char			**map_to_array(t_mlx_data *data, char **av);
void			check_line_char(char *line, int fd);
int				check_t_b_wall(char *line);
void			check_map_extention(char **av);
void			find_p_pos(t_mlx_data *data);

// Mandatory commands
int				draw_map(t_mlx_data *data);
int				key_hook(int keysym, t_mlx_data *data);
void			draw_characters(t_mlx_data *data, int i);
void			image_link(t_mlx_data *data);
void			free_destroy(t_mlx_data *data);
int				close_window(t_mlx_data *data);
void			enemy_side(t_mlx_data *data, int i, int j);

// Animation
void    		coin_animation(t_mlx_data *data, int num, char *link);
void    		stop_animation(t_mlx_data *data, int num, char *link);
void			home_animation(t_mlx_data *data, int num, char *link);
void			enemy_animation(t_mlx_data *data, int num);
void			death(t_mlx_data *data);
void			win_lose(t_mlx_data *data);

int				animation(t_mlx_data *data);

#endif