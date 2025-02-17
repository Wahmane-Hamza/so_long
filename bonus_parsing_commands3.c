/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_commands3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/17 01:47:43 by wahmane          ###   ########.fr       */
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

void	check_caracters2(char *line, t_mlx_data *data, int fd)
{
	if (data->elem.e != 1)
		error_exit("Error: Exit(E)", line, fd, NULL);
	if (data->elem.p != 1)
		error_exit("Error: Player(P)", line, fd, NULL);
	if (data->elem.c == 0)
		error_exit("Error: Coin(C)", line, fd, NULL);
	if (data->elem.m == 0)
		error_exit("Error: Enemy(M)", line, fd, NULL);
}

void	check_screen_size(t_mlx_data *data, int fd)
{
	if (data->map.map_x_len > 24)
		error_exit("ERROR: BIG WIDTH", NULL, fd, data->map.array);
	if (data->map.map_y_len > 13)
		error_exit("ERROR: BIG HEIGHT", NULL, fd, data->map.array);
}

void	set_zero(t_mlx_data *data)
{
	ft_memset(&data->elem, 0, sizeof(data->elem));
	ft_memset(&data->img, 0, sizeof(data->img));
	ft_memset(&data->map, 0, sizeof(data->map));
	ft_memset(&data->path, 0, sizeof(data->path));
}