/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:21:20 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/17 01:22:22 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	characters_animation(t_mlx_data *data, int i)
{
	static	int	d;

	if (data->elem.house_open != 0)
	{
		if (data->elem.house_open == 1)
		{
			data->img.house_open = data->path.home[1][d];
			if (d == 5)
				data->elem.house_open = 2;
			d++;
		}
		else
			data->img.house_open = data->path.home[0][i];
	}
	else
		data->img.house_close = data->path.home[2][i];
	if (data->img.side.front == 1)
		stop_animation(data, i, 0, 1);
	else if (data->img.side.front == 2)
		stop_animation(data, i, 1, 1);
	else if (data->img.side.right == 1)
		stop_animation(data, i, 2, 1);
	else if (data->img.side.right == 2)
		stop_animation(data, i, 3, 1);
	enemy_animation(data, i);
}

void	enemy_death(t_mlx_data *data, int i)
{
	find_p_pos(data);
	if (data->img.side.front == 1)
	{
		data->elem.m_posx = data->elem.p_posx;
		data->elem.m_posy = data->elem.p_posy + 1;
		data->img.enemy_back = data->path.attack[1][i];
	}
	else if (data->img.side.front == 2)
	{
		data->elem.m_posx = data->elem.p_posx;
		data->elem.m_posy = data->elem.p_posy - 1;
		data->img.enemy_front = data->path.attack[0][i];
	}
	else if (data->img.side.right == 1)
	{
		data->elem.m_posx = data->elem.p_posx + 1;
		data->elem.m_posy = data->elem.p_posy;
		data->img.enemy_left = data->path.attack[3][i];
	}
	else if (data->img.side.right == 2)
	{
		data->elem.m_posx = data->elem.p_posx - 1;
		data->elem.m_posy = data->elem.p_posy;
		data->img.enemy_right = data->path.attack[2][i];
	}
}

void	death(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (data->img.side.front == 1)
			stop_animation(data, i, 0, 0);
		else if (data->img.side.front == 2)
			stop_animation(data, i, 1, 0);
		else if (data->img.side.right == 1)
			stop_animation(data, i, 2, 0);
		else if (data->img.side.right == 2)
			stop_animation(data, i, 3, 0);
		enemy_death(data, i);
		mlx_do_sync(data->mlx);
		draw_map(data);
		usleep(200000);
		i++;
	}
}

void	win(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		data->img.map_player = data->path.map_ground;
		data->img.house_open = data->path.win[i];
		mlx_do_sync(data->mlx);
		draw_map(data);
		usleep(200000);
		i++;
	}
}
