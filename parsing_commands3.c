/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 12:15:41 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extention(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".ber", 4) != 0)
		error_exit("extention not (.ber)", NULL, -1, NULL);
	if (av[1][len - 5] == '\0' || av[1][len - 5] == '/')
		error_exit("you need name before extention", NULL, -1, NULL);
}

void	check_screen_size(t_mlx_data *data, int fd)
{
	if (data->map.map_x_len > 24)
		error_exit("ERROR: BIG WIDTH", NULL, fd, data->map.array);
	if (data->map.map_y_len > 13)
		error_exit("ERROR: BIG HEIGHT", NULL, fd, data->map.array);
}
