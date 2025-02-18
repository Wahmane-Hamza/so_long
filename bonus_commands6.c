/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:13:28 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/18 11:13:49 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int enemy_right(t_mlx_data *data, int i, int j)
{
	if (data->map.array[i][j + 1] == '0')
	{
		data->map.array[i][j] = '0';
		data->map.array[i][j + 1] = 'M';
		return (j + 1);
	}
	else if (data->map.array[i][j + 1] == 'P')
	{
		data->img.side.finish = 1;
		return (0);
	}
	else
		data->img.enemy_directions[i][j] = 1;
	return (j);
}

int	enemy_bottom(t_mlx_data *data, int i, int j)
{

	if (i != data->img.side.y && j != data->img.side.x)
	{
		if (data->map.array[i + 1][j] == '0')
		{
			data->map.array[i][j] = '0';
			data->map.array[i + 1][j] = 'M';
			data->img.enemy_directions[i + 1][j] = 2;
			data->img.enemy_directions[i][j] = 0;
			return (-1);
		}
		else if (data->map.array[i + 1][j] == 'P')
		{
			data->img.side.finish = 1;
			return (0);
		}
		else
			data->img.enemy_directions[i][j] = 3;
	}
	return (1);
}

int	enemy_top_bottom(t_mlx_data *data, int i, int j)
{

	if (data->img.enemy_directions[i][j] == 2)
		return (enemy_bottom(data, i, j));
	else if (data->img.enemy_directions[i][j] == 3)
	{
		if (data->map.array[i - 1][j] == '0')
		{
			data->map.array[i][j] = '0';
			data->map.array[i - 1][j] = 'M';
			data->img.enemy_directions[i - 1][j] = 3;
			data->img.enemy_directions[i][j] = 2;
		}
		else if (data->map.array[i - 1][j] == 'P')
		{
			data->img.side.finish = 1;
			return 0;
		}
		else
			data->img.enemy_directions[i][j] = 2;
	}
	return (1);
}

int	enemy_left_right(t_mlx_data *data, int i, int j)
{
	if (data->img.enemy_directions[i][j] == 0)
		return (enemy_right(data, i, j));
	else
	{
		if (data->map.array[i][j - 1] == '0')
		{
			data->map.array[i][j] = '0';
			data->map.array[i][j - 1] = 'M';
			data->img.enemy_directions[i][j] = 0;
			data->img.enemy_directions[i][j - 1] = 1;
		}
		else if (data->map.array[i][j - 1] == 'P')
		{
			data->img.side.finish = 1;
			return (0);
		}
		else
			data->img.enemy_directions[i][j] = 0;
	}
	return (j);
}

void move_enemy2(t_mlx_data *data, int i, int j, int k)
{
	while (data->map.array[i][j])
	{
		if (data->map.array[i][j] == 'M' && data->img.enemy_directions[i][j] < 2)
		{
			k = enemy_left_right(data, i, j);
			if (k == 0)
				break;
			j = k; 	
		}
		if (data->map.array[i][j] == 'M' && data->img.enemy_directions[i][j] >= 2)
		{
			k = enemy_top_bottom(data, i, j);
			if (k == 0)
				break;
			else if (k == -1)
			{
				data->img.side.x = j;
				data->img.side.y = i + 1;
			}
		}
		j++;
	}
}
