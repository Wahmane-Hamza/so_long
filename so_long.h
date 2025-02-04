/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:23:03 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/04 18:50:17 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef    SO_LONG_H
# define    SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>

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

typedef struct s_mlx_data
{
    void	*mlx;
	void	*mlx_win;
    t_img   img;
}   mlx_data;

# define WIDTH 400
# define HEIGHT 400

# endif