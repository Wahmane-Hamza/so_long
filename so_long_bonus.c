/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/15 12:27:57 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	death(t_mlx_data *data)
{
	int	j;

	while (j <= 9)
	{
		if (data->img.side.front == 1)
			stop_animation(data, j, "./images/bonus/death/death_front/");
		else if (data->img.side.front == 2)
			stop_animation(data, j, "./images/bonus/death/death_back/");
		else if (data->img.side.right == 1)
			stop_animation(data, j, "./images/bonus/death/death_right/");
		else if (data->img.side.right == 2)
			stop_animation(data, j, "./images/bonus/death/death-left/");
		usleep(200000);
		draw_map(data);
		j++;
	}
}

int	animation(t_mlx_data *data)
{
	static	int	i;
	static	int	j;
	static	int	k;

	if (i > 5)
		i = 0;
	if (j > 9)
		j = 0;

	if (data->img.side.finish == 1)
	{
		if (k == 0)
		{
			if (data->img.side.win != 1)
				death(data);
			mlx_clear_window(data->mlx, data->mlx_win);
		}
		win_lose(data);
		if (k == 20)
			free_destroy(data);
		k++;
	}
	else
	{
		coin_animation(data, j, "./images/bonus/coins/");
		if (data->elem.house_open != 0)
		{
			if (data->elem.house_open == 1)
			{
				home_animation(data, i, "./images/bonus/home_pic/home_to_open/");
				data->elem.house_open = 2;
			}
			else
				home_animation(data, i, "./images/bonus/home_pic/home_open/");
		}
		else
		home_animation(data, i, "./images/bonus/home_pic/home_close/");
		if (data->img.side.front == 1)
			stop_animation(data, i, "./images/bonus/stop/stop_front/");
		else if (data->img.side.front == 2)
			stop_animation(data, i, "./images/bonus/stop/stop_back/");
		else if (data->img.side.right == 1)
			stop_animation(data, i, "./images/bonus/stop/stop_right/");
		else if (data->img.side.right == 2)
			stop_animation(data, i, "./images/bonus/stop/stop_left/");
		data->img.side.enemy_path.enemy_front = "./images/bonus/enemy/enemy_front/";
		data->img.side.enemy_path.enemy_left = "./images/bonus/enemy/enemy_left/";
		data->img.side.enemy_path.enemy_back = "./images/bonus/enemy/enemy_back/";
		data->img.side.enemy_path.enemy_right = "./images/bonus/enemy/enemy_right/";
		enemy_animation(data, i);
	}
	usleep(130000);
	if (data->img.side.finish != 1)
		draw_map(data);
	i++;
	j++;
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		if (check_all(av, &data) == 0)
			return (0);
		data.map.array = map_to_array(&data, av);
		if (flood_fill_bonus(&data) == 0)
			error_exit("Error: The wall blocks the player.\n", NULL, -1, NULL);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.map.map_x_len * 80,
				data.map.map_y_len * 80, "so_long");
		image_link(&data);
		draw_map(&data);
		mlx_loop_hook(data.mlx, animation, &data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_hook(data.mlx_win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
		free_map(data.map.array);
		free(data.mlx);
		mlx_destroy_window(data.mlx, data.mlx_win);
		mlx_destroy_display(data.mlx);
	}
	else
		error_exit("Bad argement:./so_long map\n", NULL, -1, NULL);
}
