/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:36:03 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/16 15:45:02 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_death(t_mlx_data *data, int i)
{
	find_p_pos(data);
	if (data->img.side.front == 1)
	{
		data->elem.m_posx = data->elem.p_posx;
		data->elem.m_posy = data->elem.p_posy + 1;
		enemy_death_animation(data, i, "./images/bonus/attack/attack_back/", 0);
	}
	else if (data->img.side.front == 2)
	{
		data->elem.m_posx = data->elem.p_posx;
		data->elem.m_posy = data->elem.p_posy - 1;
		enemy_death_animation(data, i, "./images/bonus/attack/attack_front/", 1);
	}
	else if (data->img.side.right == 1)
	{
		data->elem.m_posx = data->elem.p_posx + 1;
		data->elem.m_posy = data->elem.p_posy;
		enemy_death_animation(data, i, "./images/bonus/attack/attack_left/", 3);
	}
	else if (data->img.side.right == 2)
	{
		data->elem.m_posx = data->elem.p_posx - 1;
		data->elem.m_posy = data->elem.p_posy;
		enemy_death_animation(data, i, "./images/bonus/attack/attack_right/", 2);
	}
}

void	death(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (data->img.side.front == 1)
			stop_animation(data, i, "./images/bonus/death/death_front/");
		else if (data->img.side.front == 2)
			stop_animation(data, i, "./images/bonus/death/death_back/");
		else if (data->img.side.right == 1)
			stop_animation(data, i, "./images/bonus/death/death_right/");
		else if (data->img.side.right == 2)
			stop_animation(data, i, "./images/bonus/death/death-left/");
		usleep(200000);
		draw_map(data);
		enemy_death(data, i);
		i++;
	}
}

void	win(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		stop_animation(data, -1, "./images/mandatory/ground.xpm");
		home_animation(data, i, "./images/bonus/win_pic/");
		usleep(200000);
		draw_map(data);
		i++;
	}
}

void    enemy_death_animation2(t_mlx_data *data, int side, char *link)
{
    if (side == 2)
	{
		data->img.enemy_right = mlx_xpm_file_to_image(data->mlx,
					link, &data->img.img_width,
					&data->img.img_height);
	}
	if (side == 3)
	{
		data->img.enemy_left = mlx_xpm_file_to_image(data->mlx,
					link, &data->img.img_width,
					&data->img.img_height);
	}
}
