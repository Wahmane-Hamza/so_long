/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:38:36 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/12 16:38:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		if (check_all(av, &data) == 0)
			return (0);
		data.map.array = map_to_array(&data, av);
		if (flood_fill(&data) == 0)
			error_exit("Error: The wall blocks the player.\n", NULL, -1, NULL);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.map.map_x_len * 80,
				data.map.map_y_len * 80, "so_long");
		image_link(&data);
		draw_map(&data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
		free_map(data.map.array);
		free(data.mlx);
		mlx_destroy_window(data.mlx, data.mlx_win);
		mlx_destroy_display(data.mlx);
	}
	else
		error_exit("Bad argement:./so_long map\n", NULL, -1, NULL);
}