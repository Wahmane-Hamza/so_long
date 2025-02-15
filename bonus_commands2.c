/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:31:57 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/15 15:28:31 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movements(t_mlx_data *data)
{
	data->elem.num_move++;
	write(1, "Number of movements: ", 21);
	ft_putnbr_fd(data->elem.num_move, 1);
	write(1, "\n", 1);
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
			data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
			data->map.array[num][data->elem.p_posx] = 'P';
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
			data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
			data->map.array[data->elem.p_posy][num] = 'P';
		}
		open_door(data, num, x_y);
	}
	print_movements(data);
}

int	key_hook(int keysym, t_mlx_data *data)
{

	if (keysym == KEY_W || keysym == KEY_UP)
		player_side(data, 2, 0, 0);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		player_side(data, 1, 0, 1);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		player_side(data, 0, 1, 2);
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		player_side(data, 0, 2, 3);
	else if (keysym == ESC || keysym == ON_DESTROY)
		free_destroy(data);
	else
		return (0);
	data->map.render = 0;
	draw_map(data);
	find_p_pos(data);
	return (1);
}

void	free_destroy(t_mlx_data *data)
{
	if (data->img.map_ground)
		mlx_destroy_image(data->mlx, data->img.map_ground);
	if (data->img.map_player)
		mlx_destroy_image(data->mlx, data->img.map_player);
	if (data->img.house_open)
		mlx_destroy_image(data->mlx, data->img.house_open);
	if (data->img.house_close)
		mlx_destroy_image(data->mlx, data->img.house_close);
	if (data->img.map_wall)
		mlx_destroy_image(data->mlx, data->img.map_wall);
	if (data->img.map_coin)
		mlx_destroy_image(data->mlx, data->img.map_coin);
	enemy_destroy(data);
	if (data->map.array)
		free_map(data->map.array);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (1);
}
