/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:46:57 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/16 16:06:04 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_mlx_data *data, int x, int y)
{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
			x * data->img.img_width, y * data->img.img_height);
}

void	draw_characters(t_mlx_data *data, int i)
{
	int	j;

	while (data->map.array[i])
	{
		j = 0;
		while (data->map.array[i][j])
		{
			if (data->map.array[i][j] == '1')
				data->img.img = data->img.map_wall;
			else if (data->map.array[i][j] == 'C')
				data->img.img = data->img.map_coin;
			else if (data->map.array[i][j] == 'E')
				home_open(data);
			else if (data->map.array[i][j] == 'P')
				data->img.img = data->img.map_player;
			else if (data->map.array[i][j] == 'M')
				enemy_side(data, i, j);
			else
				data->img.img = data->img.map_ground;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
				j * data->img.img_width, i * data->img.img_height);
			j++;
		}
		i++;
	}
}

void	image_link(t_mlx_data *data)
{
	data->img.map_player = mlx_xpm_file_to_image(data->mlx,
			"./images/bonus/stop/stop_front/1.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_ground = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/ground.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.house_close = mlx_xpm_file_to_image(data->mlx,
			"./images/bonus/home_pic/home_close/0.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.house_open = mlx_xpm_file_to_image(data->mlx,
			"./images/bonus/home_pic/home_to_open/0.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_wall = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/wall.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_coin = mlx_xpm_file_to_image(data->mlx,
			"./images/bonus/coins/0.xpm",
			&data->img.img_width,
			&data->img.img_height);
	image_link_enemy(data);
}

void    enemy_draw(t_mlx_data *data, int i, int j)
{
    if (data->img.side.finish != 1)
        enemy_side(data, i, j);
    else
        data->img.img = NULL;
}

void	change_player(t_mlx_data *data, int num, int x_y)
{
	if (x_y == 1)
	{
		data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
		data->map.array[num][data->elem.p_posx] = 'P';
		data->elem.num_move++;
	}
	else if (x_y == 2)
	{
		data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
		data->map.array[data->elem.p_posy][num] = 'P';
		data->elem.num_move++;
	}
}
