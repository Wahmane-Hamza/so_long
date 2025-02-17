/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:46:57 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/16 23:41:00 by wahmane          ###   ########.fr       */
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
				data->img.img = data->path.map_wall;
			else if (data->map.array[i][j] == 'C')
				data->img.img = data->img.map_coin;
			else if (data->map.array[i][j] == 'E')
				home_open(data);
			else if (data->map.array[i][j] == 'P')
				data->img.img = data->img.map_player;
			else if (data->map.array[i][j] == 'M')
				enemy_draw(data, i, j);
			else
				data->img.img = data->path.map_ground;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
				j * data->img.img_width, i * data->img.img_height);
			j++;
		}
		i++;
	}
}

void    enemy_draw(t_mlx_data *data, int i, int j)
{
	find_p_pos(data);
	if ((i == data->elem.p_posy + 2 || i == data->elem.p_posy + 1) 
		&& j == data->elem.p_posx)
			data->img.img = data->img.enemy_back;
	else if (i == data->elem.p_posy 
		&& (j == data->elem.p_posx + 2 || j == data->elem.p_posx + 1))
			data->img.img = data->img.enemy_left;
	else if (i == data->elem.p_posy
		&& (j == data->elem.p_posx - 2 || j == data->elem.p_posx - 1))
		data->img.img = data->img.enemy_right;
	else
		data->img.img = data->img.enemy_front;
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
