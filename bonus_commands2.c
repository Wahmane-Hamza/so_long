/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:31:57 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 15:56:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movements(t_mlx_data *data)
{
	char	*number;
	char	*number2;

	mlx_set_font(data->mlx, data->mlx_win, "9x15");
	number2 = ft_itoa(data->elem.num_move - 1);
	number = ft_itoa(data->elem.num_move);
	mlx_string_put(data->mlx, data->mlx_win, 0, 21, 0x000000,
		"Number of movement :");
	mlx_string_put(data->mlx, data->mlx_win, 1, 20, 0x000000,
		"Number of movement :");
	mlx_string_put(data->mlx, data->mlx_win, 0, 20, 0x000000,
		"Number of movement :");
	if (data->elem.num_move != 0)
	{
		mlx_string_put(data->mlx, data->mlx_win, 185, 20, 0x6BBA21, number2);
		mlx_string_put(data->mlx, data->mlx_win, 185, 21, 0x6BBA21, number2);
		mlx_string_put(data->mlx, data->mlx_win, 186, 20, 0x6BBA21, number2);
	}
	mlx_string_put(data->mlx, data->mlx_win, 186, 20, 0x000000, number);
	mlx_string_put(data->mlx, data->mlx_win, 185, 21, 0x000000, number);
	mlx_string_put(data->mlx, data->mlx_win, 185, 20, 0x000000, number);
	free(number2);
	free(number);
}

void	open_door(t_mlx_data *data, int num, char x_y)
{
	if (x_y == 'y')
	{
		if (data->map.array[num][data->elem.p_posx] == 'E'
			&& data->elem.house_open != 0)
		{
			data->img.side.finish = 1;
			data->img.side.win = 1;
			return ;
		}
	}
	else if (x_y == 'x')
	{
		if (data->map.array[data->elem.p_posy][num] == 'E'
			&& data->elem.house_open != 0)
		{
			data->img.side.finish = 1;
			data->img.side.win = 1;
			return ;
		}
	}
}

void	move_player(t_mlx_data *data, char x_y, int num)
{
	if (x_y == 'y')
	{
		if (data->map.array[num][data->elem.p_posx] == 'M')
			data->img.side.finish = 1;
		else if (data->map.array[num][data->elem.p_posx] != '1'
				&& data->map.array[num][data->elem.p_posx] != 'E')
		{
			change_player(data, num, 1);
		}
		open_door(data, num, x_y);
	}
	else if (x_y == 'x')
	{
		if (data->map.array[data->elem.p_posy][num] == 'M')
			data->img.side.finish = 1;
		else if (data->map.array[data->elem.p_posy][num] != '1'
				&& data->map.array[data->elem.p_posy][num] != 'E')
		{
			change_player(data, num, 2);
		}
		open_door(data, num, x_y);
	}
}

int	key_hook(int keysym, t_mlx_data *data)
{
	if ((keysym == KEY_W || keysym == KEY_UP) && data->img.side.finish != 1)
		player_side(data, 2, 0, 0);
	else if ((keysym == KEY_S || keysym == KEY_DOWN)
		&& data->img.side.finish != 1)
		player_side(data, 1, 0, 1);
	else if ((keysym == KEY_D || keysym == KEY_RIGHT)
		&& data->img.side.finish != 1)
		player_side(data, 0, 1, 2);
	else if ((keysym == KEY_A || keysym == KEY_LEFT)
		&& data->img.side.finish != 1)
		player_side(data, 0, 2, 3);
	else if ((keysym == ESC || keysym == ON_DESTROY)
		&& data->img.side.finish != 1)
		free_destroy(data, 0);
	else
		return (0);
	data->map.render = 0;
	if (data->img.side.finish != 1)
		draw_map(data);
	find_p_pos(data);
	return (1);
}

void	free_destroy(t_mlx_data *data, int num_exit)
{
	destroy_path(data);
	destroy_path2(data);
	destroy_path3(data);
	if (data->path.map_ground)
		mlx_destroy_image(data->mlx, data->path.map_ground);
	if (data->path.map_wall)
		mlx_destroy_image(data->mlx, data->path.map_wall);
	if (data->map.array)
		free_map(data->map.array);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(num_exit);
}
