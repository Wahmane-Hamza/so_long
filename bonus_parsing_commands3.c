/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_commands3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/14 19:32:28 by wahmane          ###   ########.fr       */
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
	if ( i < data->elem.p_posy)
		data->img.img = data->img.enemy_front;
	else if (i > data->elem.p_posy)
		data->img.img = data->img.enemy_back;
	else if (j > data->elem.p_posx)
		data->img.img = data->img.enemy_left;
	else if (j < data->elem.p_posx)
		data->img.img = data->img.enemy_right;
	else
		data->img.img = data->img.enemy_front;
}
