/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:28:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/15 18:10:36 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_coins(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map.array || !data->map.array[i])
		free_destroy(data);
	while (data->map.array[i])
	{
		j = 0;
		while (data->map.array[i][j])
		{
			if (data->map.array[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

void	put_image(t_mlx_data *data, int x, int y)
{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
			x * data->img.img_width, y * data->img.img_height);
}
void	draw_ground_player(t_mlx_data *data)
{
	int	x;
	int	y;
	int	m_x;
	int	m_y;

	find_p_pos(data);
	x = data->elem.p_posx;
	y = data->elem.p_posy;
	m_x = data->elem.m_posx;
	m_y = data->elem.m_posy;

	data->img.img = data->img.map_player;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
		x * data->img.img_width, y * data->img.img_height);
	data->img.img = data->img.map_ground;
	if (data->img.side.finish == 1)
	{
		enemy_side(data, m_y, m_x);
		if( m_x != 0 && m_y != 0)
			put_image(data, m_x, m_y);
	}
	else
	{
		if (data->map.array[y][x - 1] == '0')
			put_image(data, x - 1, y);
		if (data->map.array[y][x + 1] == '0')
			put_image(data, x + 1, y);
		if (data->map.array[y - 1][x] == '0')
			put_image(data, x, y - 1);
		if (data->map.array[y + 1][x] == '0')
			put_image(data, x, y + 1);
	}
}

void	draw_player_position(t_mlx_data *data, int i)
{
	int	j;

	while (data->map.array[i])
	{
		j = 0;
		while (data->map.array[i][j])
		{

			if (data->map.array[i][j] == 'C')
				data->img.img = data->img.map_coin;
			else if (data->map.array[i][j] == 'E')
					home_open(data);
			else if (data->map.array[i][j] == 'M')
			{
				if (data->img.side.finish != 1)
					enemy_side(data, i, j);
				else
					data->img.img = NULL;
			}
			else
				data->img.img = NULL;
			if (data->img.img)
				put_image(data, j, i);
			j++;
		}
		i++;
	}
	draw_ground_player(data);
}

int	draw_map(t_mlx_data *data)
{
	int	i;

	i = 0;
	if (data->elem.house_open != 2)
		data->elem.house_open = 0;
	if (check_coins(data) == 1 && data->elem.house_open == 0)
		data->elem.house_open = 1;
	if (data->map.render == 1)
		draw_characters(data, i);
	else
		draw_player_position(data, i);
	return (1);
}
int	close_window(t_mlx_data *data)
{
	free_destroy(data);
	return (0);
}
