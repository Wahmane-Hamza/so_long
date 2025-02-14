/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_commands3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/14 18:50:12 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_extention(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
		{
			if (ft_strncmp("ber", &av[1][i + 1], ft_strlen(&av[1][i + 1])) != 0
				|| ft_strncmp("ber", &av[1][i + 1], 3) != 0)
				error_exit("extention not (.ber)", NULL, -1, NULL);
		}
		i++;
	}
}
void	enemy_side(t_mlx_data *data, int i, int j)
{
	find_p_pos(data);
	data->img.side.attack_front = 0;
	data->img.side.attack_right = 0;
	if ( i < data->elem.p_posy)
	{
		data->img.img = data->img.enemy_front;
		if (data->elem.p_posy - 1 == i && data->elem.p_posx == j)
			data->img.side.attack_front = 1;
	}
	else if (i > data->elem.p_posy)
	{
		data->img.img = data->img.enemy_back;
		if (data->elem.p_posy + 1 == i && data->elem.p_posx == j)
			data->img.side.attack_front = 2;

	}
	else if (j > data->elem.p_posx)
	{
		data->img.img = data->img.enemy_left;
		if (data->elem.p_posy == i && data->elem.p_posx + 1 == j)
			data->img.side.attack_right = 2;
	}
	else if (j < data->elem.p_posx)
	{
		data->img.img = data->img.enemy_right;
		if (data->elem.p_posy == i && data->elem.p_posx - 1 == j)
			data->img.side.attack_right = 1;

	}
	else
	{
		data->img.side.attack_front = 0;
		data->img.img = data->img.enemy_front;
	}
}
