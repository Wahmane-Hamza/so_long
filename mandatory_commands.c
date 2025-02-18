/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:28:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 11:53:20 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coins(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
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
	data->img.map_ground = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/ground.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_player = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/player.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.house_close = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/house_close.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.house_open = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/house_open.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_wall = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/wall.xpm",
			&data->img.img_width,
			&data->img.img_height);
	data->img.map_coin = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/coin.xpm",
			&data->img.img_width,
			&data->img.img_height);
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
			else if (data->map.array[i][j] == 'E' && data->elem.house_open != 1)
				data->img.img = data->img.house_close;
			else if (data->map.array[i][j] == 'E' && data->elem.house_open == 1)
				data->img.img = data->img.house_open;
			else if (data->map.array[i][j] == 'P')
				data->img.img = data->img.map_player;
			else
				data->img.img = data->img.map_ground;
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
				j * data->img.img_width, i * data->img.img_height);
			j++;
		}
		i++;
	}
}

int	draw_map(t_mlx_data *data)
{
	int	i;

	i = 0;
	data->elem.house_open = 0;
	if (check_coins(data) == 1)
		data->elem.house_open = 1;
	draw_characters(data, i);
	return (1);
}

int	close_window(t_mlx_data *data)
{
	free_destroy(data);
	return (0);
}
