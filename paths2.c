/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:26:40 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/18 11:58:33 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    coin_link_array(t_mlx_data *data, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    (void)data;
    i = 0;
    while(i <= 8)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.coin[i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.coin[i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    win_link_array(t_mlx_data *data, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    (void)data;
    i = 0;
    while(i <= 8)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.win[i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.win[i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    win_lose_link(t_mlx_data *data)
{

    data->path.win_lose[0] = mlx_xpm_file_to_image(data->mlx,
        "./images/bonus/win_lose/win.xpm",
        &data->img.img_width_win,
        &data->img.img_height_win);
    if (!data->path.win_lose[0])
            free_destroy(data, 1);
    data->path.win_lose[1] = mlx_xpm_file_to_image(data->mlx,
        "./images/bonus/win_lose/game_over.xpm",
        &data->img.img_width_lose,
        &data->img.img_height_lose);
    if (!data->path.win_lose[1])
            free_destroy(data, 1);
}

void	space_link(t_mlx_data *data)
{
	data->path.map_ground = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/ground.xpm",
			&data->img.img_width,
			&data->img.img_height);
    if (!data->path.map_ground)
            free_destroy(data, 1);
	data->path.map_wall = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/wall.xpm",
			&data->img.img_width,
			&data->img.img_height);
    if (!data->path.map_wall)
        free_destroy(data, 1);
}

void    first_link(t_mlx_data *data)
{
    data->img.enemy_front = data->path.enemy[0][0];
    data->img.enemy_back = data->path.enemy[1][0];
    data->img.enemy_right = data->path.enemy[2][0];
    data->img.enemy_left = data->path.enemy[3][0];
    data->img.house_close = data->path.home[2][0];
    data->img.house_open = data->path.home[1][0];
    data->img.map_coin = data->path.coin[0];
    data->img.map_player = data->path.player[0][0];
    
}
