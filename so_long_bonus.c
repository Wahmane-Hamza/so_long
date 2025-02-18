/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/18 13:53:31 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		if (check_all(av, &data) == 0)
			return (0);
		data.map.array = map_to_array(&data, av);
		if (flood_fill_bonus(&data) == 0)
			error_exit("Error: The wall blocks the player.\n", NULL, -1, NULL);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (EXIT_FAILURE);
		data.mlx_win = mlx_new_window(data.mlx, data.map.map_x_len * 80,
				data.map.map_y_len * 80, "so_long");
		if (!data.mlx_win)
			return (EXIT_FAILURE);
		path(&data);
		draw_map(&data);
		mlx_loop_hook(data.mlx, animation, &data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_hook(data.mlx_win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
		free_destroy(&data, 0);
	}
	else
		error_exit("Bad argement:./so_long map\n", NULL, -1, NULL);
}
