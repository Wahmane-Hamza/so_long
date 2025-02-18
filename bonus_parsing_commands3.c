/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_commands3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 13:53:42 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_extention(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".ber", 4) != 0)
		error_exit("extention not (.ber)", NULL, -1, NULL);
	if (av[1][len - 5] == '\0' || av[1][len - 5] == '/')
		error_exit("you need name before extention", NULL, -1, NULL);
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
	ft_memset(&data, 0, sizeof(data));
}
