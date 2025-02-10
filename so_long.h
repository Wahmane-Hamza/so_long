/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 18:36:41 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pixels_ptr;
	int			bits_per_pixels;
	int			endian;
	int			line_len;
	int			pixel;
	int			step_right_left;
	int			step_top_bottum;
}				t_img;

typedef struct l_elem_data
{
	int			p;
	int			e;
	int			c;
	int			p_posx;
	int			p_posy;
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

int				check_all(char **av, t_mlx_data *data);
int				flood_fill(t_mlx_data *data);
void			free_map(char **map);
int				error_exit(char *message, char *line, int fd, char **array);
char			**map_to_array(t_mlx_data *data, char **av);
void			check_line_char(char *line, int fd);
int				check_t_b_wall(char *line);

#endif