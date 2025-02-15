/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:41 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/15 14:01:19 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    enemy_animation(t_mlx_data *data, int num)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(num);
	path = ft_strjoin(data->img.side.enemy_path.enemy_front, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	data->img.enemy_front = mlx_xpm_file_to_image(data->mlx,
			full_path, &data->img.img_width,
			&data->img.img_height);
	free(full_path);
	number = ft_itoa(num);
	path = ft_strjoin(data->img.side.enemy_path.enemy_back, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	data->img.enemy_back = mlx_xpm_file_to_image(data->mlx,
			full_path, &data->img.img_width,
			&data->img.img_height);
	free(full_path);
	enemy_animation2(data, num);
}

void    home_animation(t_mlx_data *data, int num, char *link)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(num);
	path = ft_strjoin(link, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
	if (data->elem.house_open != 0)
	{
		data->img.house_open = mlx_xpm_file_to_image(data->mlx,
					full_path, &data->img.img_width,
					&data->img.img_height);
	}
	else
	{
		data->img.house_close = mlx_xpm_file_to_image(data->mlx,
				full_path, &data->img.img_width,
				&data->img.img_height);
	}
	free(full_path);
}

void    coin_animation(t_mlx_data *data, int num, char *link)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(num);
	path = ft_strjoin(link, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
    data->img.map_coin = mlx_xpm_file_to_image(data->mlx,
                full_path, &data->img.img_width,
                &data->img.img_height);
	free(full_path);
}

void    stop_animation(t_mlx_data *data, int num, char *link)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(num);
	path = ft_strjoin(link, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
    data->img.map_player = mlx_xpm_file_to_image(data->mlx,
                full_path, &data->img.img_width,
                &data->img.img_height);
	free(full_path);
}

void win_lose(t_mlx_data *data)
{
	int	x_center;
	int	y_center;
	char	*link;

	if (data->img.side.win == 1)
		link = "./images/bonus/win_lose/win.xpm";
	else
		link = "./images/bonus/win_lose/game_over.xpm";
    data->img.img = mlx_xpm_file_to_image(data->mlx,
            link,
            &data->img.img_width,
            &data->img.img_height);
	if ((data->map.map_x_len * 80) > data->img.img_width)
		x_center = ((data->map.map_x_len * 80) - data->img.img_width) / 2 ;
	else
		x_center = 0 ;
	if ((data->map.map_y_len * 80) > data->img.img_height)
		y_center = ((data->map.map_y_len * 80) - data->img.img_height) / 2 ;
	else
		y_center = 0;
    mlx_put_image_to_window(data->mlx, data->mlx_win,data->img.img ,x_center, y_center);
}
