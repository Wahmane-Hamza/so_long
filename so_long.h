/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/08 13:39:47 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef    SO_LONG_H
# define    SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_img
{
    void	*img_ptr;
	char	*img_pixels_ptr;
	int     bits_per_pixels;
	int     endian;
	int     line_len;
    int     pixel;
    int     step_right_left;
    int     step_top_bottum;
}   t_img;

typedef struct l_elem_data
{
    int P;
    int E;
    int map_x;
    int map_y;
    int P_posx;
    int P_posy;
}   elem_data;

typedef struct t_map_data
{
    char    **array;
    int     map_x_len;
    int     map_y_len;
}   map_data;

typedef struct s_mlx_data
{
    void        *mlx;
	void        *mlx_win;
    t_img       img;
    elem_data   elem;
    map_data    map;
}   mlx_data;


int WIDTH = 0;
int HEIGHT = 0;


int	check_element_map();

# endif