/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/16 16:25:07 by wahmane          ###   ########.fr       */
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
	int	finish;
	int	win;
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
	int			m_posx;
	int			m_posy;
	int			num_move;
}				t_elem_data;

typedef struct t_map_data
{
	char		**array;
	int			render;
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

// flood_fill_bonus
int				flood_fill_bonus(t_mlx_data *data);

// bonus_parsing_commands
int				error_exit(char *message, char *line, int fd, char **array);
int				check_t_b_wall(char *line);
int				check_caracters(char *line, t_mlx_data *data, int i);
void			*check_element_map(char *line, t_mlx_data *data, int fd, int len);
int				check_all(char **av, t_mlx_data *data);

// bonus_parsing_commands2
void			find_p_pos(t_mlx_data *data);
void			free_map(char **map);
void			*map_len(t_mlx_data *data, char **av);
char			**map_to_array(t_mlx_data *data, char **av);
void			check_line_char(char *line, int fd);

// bonus_parsing_commands3
void			check_map_extention(char **av);
void			enemy_side(t_mlx_data *data, int i, int j);
void			check_caracters2(char *line, t_mlx_data *data, int fd);
void			check_screen_size(t_mlx_data *data, int fd);

// Animation
void			enemy_animation(t_mlx_data *data, int num);
void			home_animation(t_mlx_data *data, int num, char *link);
void    		coin_animation(t_mlx_data *data, int num, char *link);
void    		stop_animation(t_mlx_data *data, int num, char *link);
void			win_lose(t_mlx_data *data);

// animation2
void			enemy_animation2(t_mlx_data *data, int num);
void			enemy_death_animation(t_mlx_data *data, int num, char *link, int side);
void			characters_animation(t_mlx_data *data, int i);
void			finish(t_mlx_data *data, int k);
int				animation(t_mlx_data *data);

// animation 3
void			enemy_death(t_mlx_data *data, int i);
void			death(t_mlx_data *data);
void			win(t_mlx_data *data);
void			enemy_death_animation2(t_mlx_data *data, int side, char *link);

// bonus_commands
int				check_coins(t_mlx_data *data);
void			draw_ground(t_mlx_data *data, int y, int x);
void			draw_ground_player(t_mlx_data *data);
void			draw_player_position(t_mlx_data *data, int i);
int				draw_map(t_mlx_data *data);


// bonus_commands2
void			print_movements(t_mlx_data *data);
void			open_door(t_mlx_data *data, int num, char x_y);
void			move_player(t_mlx_data *data, char x_y, int num);
int				key_hook(int keysym, t_mlx_data *data);
void			free_destroy(t_mlx_data *data);

// bonus_commands3
void			image_link_enemy(t_mlx_data *data);
void			player_side(t_mlx_data*data, int front, int right, int move);
void			enemy_destroy(t_mlx_data *data);
void			home_open(t_mlx_data *data);
int				close_window(t_mlx_data *data);

// bonus_commands4
void			put_image(t_mlx_data *data, int x, int y);
void			draw_characters(t_mlx_data *data, int i);
void			image_link(t_mlx_data *data);
void			enemy_draw(t_mlx_data *data, int i, int j);
void			change_player(t_mlx_data *data, int num, int x_y);

#endif