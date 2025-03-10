/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/24 18:41:14 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extention(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".ber", 4) != 0)
		error_exit("Error\nextention not (.ber)", NULL, -1, NULL);
	if (av[1][len - 5] == '\0' || av[1][len - 5] == '/')
		error_exit("Error\nyou need name before extention", NULL, -1, NULL);
}

void	check_screen_size(t_mlx_data *data, int fd)
{
	if (data->map.map_x_len > 48)
		error_exit("Error\nBIG WIDTH", NULL, fd, data->map.array);
	if (data->map.map_y_len > 26)
		error_exit("Error\nBIG HEIGHT", NULL, fd, data->map.array);
}

void	image_link2(t_mlx_data *data)
{
	data->img.house_close = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/house_close.xpm",
			&data->img.img_width,
			&data->img.img_height);
	if (!data->img.house_close)
		free_destroy(data);
	data->img.house_open = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/house_open.xpm",
			&data->img.img_width,
			&data->img.img_height);
	if (!data->img.house_open)
		free_destroy(data);
	data->img.map_wall = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/wall.xpm",
			&data->img.img_width,
			&data->img.img_height);
	if (!data->img.map_wall)
		free_destroy(data);
	data->img.map_coin = mlx_xpm_file_to_image(data->mlx,
			"./images/mandatory/coin.xpm",
			&data->img.img_width,
			&data->img.img_height);
	if (!data->img.map_coin)
		free_destroy(data);
}
