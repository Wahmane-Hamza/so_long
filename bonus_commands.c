/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:28:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 11:52:43 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_coins(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map.array || !data->map.array[i])
		free_destroy(data, 1);
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

void	draw_ground(t_mlx_data *data, int y, int x)
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.map_player,
		x * data->img.img_width, y * data->img.img_height);
	data->img.img = data->path.map_ground;
	if (data->img.side.finish == 1 && data->img.side.win != 1)
	{
		enemy_draw(data, m_y, m_x);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
		m_x * data->img.img_width, m_y * data->img.img_height);
	}
	else
		draw_ground(data, y, x);
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
			else if (data->map.array[i][j] == 'M' && data->img.side.finish != 1)
			{
				enemy_ground(data, i, j);
				enemy_draw(data, i, j);
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
	print_movements(data);
	return (1);
}
