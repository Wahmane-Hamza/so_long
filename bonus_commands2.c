/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:31:57 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/14 17:07:21 by wahmane          ###   ########.fr       */
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
			write(1, "Congratulations! You won!", 25);
			free_destroy(data);
		}
	}
	else if (x_y == 'x')
	{
		if (data->map.array[data->elem.p_posy][num] == 'E'
			&& data->elem.house_open != 0)
		{
			write(1, "Congratulations! You won!", 25);
			free_destroy(data);
		}
	}
}

void	move_player(t_mlx_data *data, char x_y, int num)
{
	if (x_y == 'y')
	{
		if (data->map.array[num][data->elem.p_posx] != '1'
			&& data->map.array[num][data->elem.p_posx] != 'E')
		{
			data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
			data->map.array[num][data->elem.p_posx] = 'P';
			print_movements(data);
		}
		open_door(data, num, x_y);
	}
	else if (x_y == 'x')
	{
		if (data->map.array[data->elem.p_posy][num] != '1'
			&& data->map.array[data->elem.p_posy][num] != 'E')
		{
			data->map.array[data->elem.p_posy][data->elem.p_posx] = '0';
			data->map.array[data->elem.p_posy][num] = 'P';
			print_movements(data);
		}
		open_door(data, num, x_y);
	}
}

int	key_hook(int keysym, t_mlx_data *data)
{
	data->img.side.front = 1;
	data->img.side.right = 0;
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		data->img.side.front = 2;
		data->img.side.right = 0;
		move_player(data, 'y', data->elem.p_posy - 1);
	}
	else if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		data->img.side.front = 1;
		data->img.side.right = 0;
		move_player(data, 'y', data->elem.p_posy + 1);
	}
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		data->img.side.front = 0;
		data->img.side.right = 1;
		move_player(data, 'x', data->elem.p_posx + 1);
	}
	else if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		data->img.side.front = 0;
		data->img.side.right = 2;
		move_player(data, 'x', data->elem.p_posx - 1);
	}
	else if (keysym == ESC || keysym == ON_DESTROY)
		free_destroy(data);
	else
		return (0);
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_map(data);
	find_p_pos(data);
	return (1);
}

void	free_destroy(t_mlx_data *data)
{
	if (data->img.map_ground)
		mlx_destroy_image(data->mlx, data->img.map_ground);
	if (data->img.enemy_front)
		mlx_destroy_image(data->mlx, data->img.enemy_front);
	if (data->img.enemy_back)
		mlx_destroy_image(data->mlx, data->img.enemy_back);
	if (data->img.enemy_left)
		mlx_destroy_image(data->mlx, data->img.enemy_left);
	if (data->img.enemy_right)
		mlx_destroy_image(data->mlx, data->img.enemy_right);
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
