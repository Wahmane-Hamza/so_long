/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_commands3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:32:18 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/18 15:41:13 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
		x * data->img.img_width, y * data->img.img_height);
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

	find_p_pos(data);
	x = data->elem.p_posx;
	y = data->elem.p_posy;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.map_player,
		x * data->img.img_width, y * data->img.img_height);
	data->img.img = data->img.map_ground;
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
			else if (data->map.array[i][j] == 'E' && data->elem.house_open != 1)
				data->img.img = data->img.house_close;
			else if (data->map.array[i][j] == 'E' && data->elem.house_open == 1)
				data->img.img = data->img.house_open;
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
