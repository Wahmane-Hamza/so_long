/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:22:37 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/04 18:56:36 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_input(int keysym, mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("the %d key has been pressed .\n", keysym);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	else if (keysym == 65364)
	{	
		data->img.step_top_bottum += 20;
	}
	else if (keysym == 65362)
	{	
		data->img.step_top_bottum -= 20;
	}
	else if (keysym == 65363)
	{	
		data->img.step_right_left += 20;
	}
	else if (keysym == 65361)
	{	
		data->img.step_right_left -= 20;
	}
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, data->img.step_right_left, data->img.step_top_bottum);
	printf("the %d key has been pressed .\n", keysym);
	return(0);
}

int	main(void)
{
	mlx_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);

	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}

	data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);

	int x = 0;
    int y = 0;
    data.img.step_right_left = 0;
    data.img.step_top_bottum = 0;
	while (++y < 20)
	{
		x = 0;
		while (++x < 20)
		{
			data.img.pixel = (y * data.img.line_len + x * (data.img.bits_per_pixels / 8));
			*((unsigned int *)(data.img.pixel + data.img.img_pixels_ptr)) = 0x0000FF;
		}
	}
	mlx_key_hook(data.mlx_win, handle_input, &data);

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, 0, 0);
	mlx_loop(data.mlx);

	mlx_destroy_window(data.mlx, data.mlx_win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
