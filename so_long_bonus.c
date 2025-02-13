/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/13 16:28:34 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int	animation(t_mlx_data *data)
{
	static	int	i;
	static	int	j;


	if (i > 5)
		i = 0;
	if (j > 9)
		j = 0;
	coin_animation(data, j, "./images/bonus/coins/");
	if (data->img.side.front == 1)
		stop_animation(data, i, "./images/bonus/stop/stop_front/");
	else if (data->img.side.front == 2)
		stop_animation(data, i, "./images/bonus/stop/stop_back/");
	else if (data->img.side.right == 1)
		stop_animation(data, i, "./images/bonus/stop/stop_right/");
	else if (data->img.side.right == 2)
		stop_animation(data, i, "./images/bonus/stop/stop_left/");
	usleep(100000);
	draw_map(data);
	i++;
	j++;
	return (1);
}

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
		mlx_loop_hook(data.mlx, animation, &data);
		data.elem.num_move = 0;
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
