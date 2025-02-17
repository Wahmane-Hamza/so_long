/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:41 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/17 01:22:03 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    enemy_animation(t_mlx_data *data, int num)
{
	data->img.enemy_front = data->path.enemy[0][num];
	data->img.enemy_back = data->path.enemy[1][num];
	data->img.enemy_right =  data->path.enemy[2][num];
	data->img.enemy_left =  data->path.enemy[3][num];
}

void    stop_animation(t_mlx_data *data, int i, int j, int alive)
{
	if (alive == 1)
		data->img.map_player = data->path.player[j][i];
	else
		data->img.map_player = data->path.death[j][i];
}

void win_lose(t_mlx_data *data)
{
	int	x_center;
	int	y_center;

	if (data->img.side.win == 1)
		data->img.img = data->path.win_lose[0];
	else
		data->img.img = data->path.win_lose[1];
	if ((data->map.map_x_len * 80) > data->img.img_width_win)
		x_center = ((data->map.map_x_len * 80) - data->img.img_width_win) / 2 ;
	else
		x_center = 0 ;
	if ((data->map.map_y_len * 80) > data->img.img_height_win)
		y_center = ((data->map.map_y_len * 80) - data->img.img_height_win) / 2 ;
	else
		y_center = 0;
    mlx_put_image_to_window(data->mlx, data->mlx_win,data->img.img ,x_center, y_center);
}

void	finish(t_mlx_data *data, int k)
{
	if (k == 0)
	{
		if (data->img.side.win != 1)
			death(data);
		else
			win(data);
		mlx_clear_window(data->mlx, data->mlx_win);
		sleep(1);
	}
	win_lose(data);
	if (k == 12)
		free_destroy(data);
}

int	animation(t_mlx_data *data)
{
	static	int	i;
	static	int	j;
	static	int	k;

	if (i > 5)
		i = 0;
	if (j > 8)
		j = 0;
	if (data->img.side.finish == 1)
	{
		finish(data, k);
		k++;
	}
	else
	{
		data->img.map_coin = data->path.coin[j];
		characters_animation(data, i);
	}
	usleep(130000);
	if (data->img.side.finish != 1)
		draw_map(data);
	i++;
	j++;
	return (1);
}