/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_commands3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:28:54 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/16 23:50:29 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    player_side(t_mlx_data*data, int front, int right, int move)
{
    data->img.side.front = front;
	data->img.side.right = right;
    if (move == 0)
		move_player(data, 'y', data->elem.p_posy - 1);
    else if (move == 1)
		move_player(data, 'y', data->elem.p_posy + 1);
    else if (move == 2)
		move_player(data, 'x', data->elem.p_posx + 1);
    else if (move == 3)
        move_player(data, 'x', data->elem.p_posx - 1);
}

void	enemy_destroy(t_mlx_data *data)
{
    if (data->img.enemy_front)
		mlx_destroy_image(data->mlx, data->img.enemy_front);
	if (data->img.enemy_back)
		mlx_destroy_image(data->mlx, data->img.enemy_back);
	if (data->img.enemy_left)
		mlx_destroy_image(data->mlx, data->img.enemy_left);
	if (data->img.enemy_right)
		mlx_destroy_image(data->mlx, data->img.enemy_right);
}

void	home_open(t_mlx_data *data)
{
	if (data->elem.house_open != 0)
		data->img.img = data->img.house_open;
	else
		data->img.img = data->img.house_close;
}

int	close_window(t_mlx_data *data)
{
	free_destroy(data);
	return (0);
}
