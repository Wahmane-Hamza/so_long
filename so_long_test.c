/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:22:37 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/11 15:18:14 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void create_element_image(t_mlx_data data, char element, int x, int y)
// {
//     int color;

//     data.img.img_ptr = mlx_new_image(data.mlx, 100, 100);
//     data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
//             &data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);

//     if (element == 'P')
//         color = 0xFF0000;
// 	else if (element == 'C')
//         color = 0x00FF00;
// 	else if (element == '1')
//         color = 0x0000FF;
// 	else if (element == 'E')
//         color = 0xF0F0F0;
// 	else
// 		color = 0x0F000F;

//     int x_pos, y_pos, pixel_pos;
//     y_pos = 0;
//     while (y_pos < 100)
// 	{
//         x_pos = 0;
//         while (x_pos < 100)
//         {
//             pixel_pos = (y_pos)  * data.img.line_len + x_pos
// *(data.img.bits_per_pixels / 8);
//             *((unsigned int *)(data.img.img_pixels_ptr + pixel_pos)) = color;
//             x_pos++;
//         }
//         y_pos++;
//     }

//     mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, x, y);
// }

// void	draw_map(t_mlx_data data , int x , int y)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("./maps/map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	(void)x;
// 	(void)y;
// 	data.elem.map_y = 0;
// 	data.elem.P_posx = 0;
// 	data.elem.P_posy = 0;
// 	while (line)
// 	{
// 		i = 0;
// 		data.elem.map_x = 0;
// 		while (line[i] != '\n' && line[i] != '\0')
// 		{
// 			if (line[i] == '1')
// 				create_element_image(data, '1', data.elem.map_x,data.elem.map_y);
// 			else if (line[i] == 'C')
// 				create_element_image(data, 'C',data.elem.map_x,data.elem.map_y);
// 			else if (line[i] == 'E')
// 				create_element_image(data,'E',data.elem.map_x,data.elem.map_y);
// 			else if (line[i] == 'P')
// 				create_element_image(data,'P',data.elem.map_x,data.elem.map_y);
// 			else
// 				create_element_image(data,'0',data.elem.map_x,data.elem.map_y);
// 			data.elem.map_x+= 100;
// 			i++;
// 		}
// 		data.elem.map_y+= 100;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// }

// int	handle_input(int keysym,t_mlx_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("the%d key has been pressed .\n",keysym);
// 		mlx_destroy_window(data->mlx,data->mlx_win);
// 		mlx_destroy_display(data->mlx);
// 		free(data->mlx);
// 		exit(1);
// 	}
// 	else if (keysym == 65364)
// 	{
// 		data->img.step_top_bottum+= 100;
// 		mlx_clear_window(data->mlx,data->mlx_win);
// 		draw_map(*data,data->img.step_right_left,data->img.step_top_bottum);
// 	}
// 	else if (keysym == 65362)
// 	{
// 		data->img.step_top_bottum-= 100;
// 		mlx_clear_window(data->mlx,data->mlx_win);
// 		draw_map(*data,data->img.step_right_left,data->img.step_top_bottum);
// 	}
// 	else if (keysym == 65363)
// 	{
// 		data->img.step_right_left+= 100;
// 		mlx_clear_window(data->mlx,data->mlx_win);
// 		draw_map(*data,data->img.step_right_left,data->img.step_top_bottum);
// 	}
// 	else if (keysym == 65361)
// 	{
// 		data->img.step_right_left-= 100;
// 		mlx_clear_window(data->mlx,data->mlx_win);
// 		draw_map(*data,data->img.step_right_left,data->img.step_top_bottum);
// 	}

// 	printf("the %d key has been pressed .\n", keysym);
// 	return (0);
// }


int main(int ac , char **av)
{
	int			x;
	int			y;
	int			pixel_pos;
	t_mlx_data	data;

	if (ac == 2)
	{
		if (check_all(av, &data) == 0)
			return (0);
		data.map.array = map_to_array(&data, av);
		if (flood_fill(&data) == 0)
			error_exit("Error: The wall blocks the player.\n", NULL, -1, NULL);

		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (1);

		data.mlx_win = mlx_new_window(data.mlx,data.map.map_x_len * 80,data.map.map_y_len  * 80, "So Long");
		if (data.mlx_win == NULL)
		{
			mlx_destroy_display(data.mlx);
			free(data.mlx);
			return (1);
		}
		data.img.img_ptr = mlx_new_image(data.mlx,data.map.map_x_len,data.map.map_y_len);
		data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
				&data.img.bits_per_pixels,&data.img.line_len, &data.img.endian);
		y = 0;
		while (y < data.map.map_y_len)
		{
			x = 0;
			while (x < data.map.map_x_len)
			{
				pixel_pos = y*data.img.line_len + x *(data.img.bits_per_pixels / 8);
				*((unsigned int *)(data.img.img_pixels_ptr + pixel_pos)) = 0xFF00FF;
				x++;
			}
			y++;
		}
		// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, 0, 0);
		// data.img.step_right_left = 0;
		// data.img.step_top_bottum = 0;
		// draw_map(data, 0 , 0);
		// mlx_key_hook(data.mlx_win, handle_input, &data);
		mlx_loop(data.mlx);
		mlx_destroy_window(data.mlx, data.mlx_win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		free_map(data.map.array);
		return (0);
	}
	else
		error_exit("Bad argement:./so_long map\n", NULL, -1, NULL);
}
