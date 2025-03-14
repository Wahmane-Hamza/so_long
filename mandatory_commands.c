/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:28:43 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 16:14:10 by hwahmane         ###   ########.fr       */
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
	if (!data->img.map_ground)
		free_destroy(data);
	data->img.map_player = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/player.xpm",
			&data->img.img_width,
			&data->img.img_height);
	if (!data->img.map_player)
		free_destroy(data);
	image_link2(data);
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
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, j
				* data->img.img_width, i * data->img.img_height);
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
