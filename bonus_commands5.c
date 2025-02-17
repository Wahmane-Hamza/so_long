/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:36:03 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/17 01:26:03 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_path(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 9)
		{
			if (data->path.attack[i][j])
				mlx_destroy_image(data->mlx, data->path.attack[i][j]);
			if (data->path.death[i][j])
				mlx_destroy_image(data->mlx, data->path.death[i][j]);
			j++;
		}
		i++;
	}
}

void	destroy_path2(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 6)
		{
			if (data->path.enemy[i][j])
				mlx_destroy_image(data->mlx, data->path.enemy[i][j]);
			if (data->path.player[i][j])
				mlx_destroy_image(data->mlx, data->path.player[i][j]);
			if (i < 3)
				if (data->path.home[i][j])
					mlx_destroy_image(data->mlx, data->path.home[i][j]);
		j++;
		}
		i++;
	}
}

void	destroy_path3(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (data->path.coin[i])
			mlx_destroy_image(data->mlx, data->path.coin[i]);
		if (data->path.win[i])
			mlx_destroy_image(data->mlx, data->path.win[i]);
		if (i < 2)
			if (data->path.win_lose[i])
				mlx_destroy_image(data->mlx, data->path.win_lose[i]);
		i++;
	}
}

void    path(t_mlx_data *data)
{
    enemy_link_array(data, 0, "./images/bonus/enemy/enemy_front/");
    enemy_link_array(data, 1, "./images/bonus/enemy/enemy_back/");
    enemy_link_array(data, 2, "./images/bonus/enemy/enemy_right/");
    enemy_link_array(data, 3, "./images/bonus/enemy/enemy_left/");
    player_link_array(data, 0, "./images/bonus/stop/stop_front/");
    player_link_array(data, 1, "./images/bonus/stop/stop_back/");
    player_link_array(data, 2, "./images/bonus/stop/stop_right/");
    player_link_array(data, 3, "./images/bonus/stop/stop_left/");
    attack_link_array(data, 0, "./images/bonus/attack/attack_front/");
    attack_link_array(data, 1, "./images/bonus/attack/attack_back/");
    attack_link_array(data, 2, "./images/bonus/attack/attack_right/");
    attack_link_array(data, 3, "./images/bonus/attack/attack_left/");
    death_link_array(data, 0, "./images/bonus/death/death_front/");
    death_link_array(data, 1, "./images/bonus/death/death_back/");
    death_link_array(data, 2, "./images/bonus/death/death_right/");
    death_link_array(data, 3, "./images/bonus/death/death-left/");
    home_link_array(data, 0, "./images/bonus/home_pic/home_open/");
    home_link_array(data, 1, "./images/bonus/home_pic/home_to_open/");
    home_link_array(data, 2, "./images/bonus/home_pic/home_close/");
    coin_link_array(data, "./images/bonus/coins/");
    win_link_array(data, "./images/bonus/win_pic/");
    win_lose_link(data);
    space_link(data);
    first_link(data);
}