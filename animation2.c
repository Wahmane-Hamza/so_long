/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:21:20 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/16 15:57:36 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    enemy_animation2(t_mlx_data *data, int num)
{
    char	*path;
	char	*number;
	char	*full_path;

    number = ft_itoa(num);
	path = ft_strjoin(data->img.side.enemy_path.enemy_right, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	data->img.enemy_right = mlx_xpm_file_to_image(data->mlx,
			full_path, &data->img.img_width,
			&data->img.img_height);
	free(full_path);
	number = ft_itoa(num);
	path = ft_strjoin(data->img.side.enemy_path.enemy_left, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	data->img.enemy_left = mlx_xpm_file_to_image(data->mlx,
			full_path, &data->img.img_width,
			&data->img.img_height);
	if (data->img.enemy_right == NULL || data->img.enemy_left == NULL)
		free_destroy(data);
	free(full_path);
}

void    enemy_death_animation(t_mlx_data *data, int num, char *link, int side)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(num);
	path = ft_strjoin(link, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	if (side == 0)
	{
		data->img.enemy_back = mlx_xpm_file_to_image(data->mlx,
					full_path, &data->img.img_width,
					&data->img.img_height);
	}
	if (side == 1)
	{
		data->img.enemy_front = mlx_xpm_file_to_image(data->mlx,
					full_path, &data->img.img_width,
					&data->img.img_height);
	}
	enemy_death_animation2(data, side, full_path);
	free(full_path);
}

void	characters_animation(t_mlx_data *data, int i)
{
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

void	finish(t_mlx_data *data, int k)
{
	if (k == 0)
	{
		if (data->img.side.win != 1)
			death(data);
		else
			win(data);
		mlx_clear_window(data->mlx, data->mlx_win);
		sleep(1);
	}
	win_lose(data);
	if (k == 12)
		free_destroy(data);
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
		finish(data, k);
		k++;
	}
	else
	{
		coin_animation(data, j, "./images/bonus/coins/");
		characters_animation(data, i);
	}
	usleep(130000);
	if (data->img.side.finish != 1)
		draw_map(data);
	i++;
	j++;
	return (1);
}
