/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:22:37 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/06 14:03:04 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_element_image(mlx_data data, char element, int x, int y)
{
    int color;
    

    data.img.img_ptr = mlx_new_image(data.mlx, 100, 100);
    data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
            &data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);
    
    if (element == 'P')
        color = 0xFF0000;
	else if (element == 'C') 
        color = 0x00FF00;
	else if (element == '1') 
        color = 0x0000FF;
	else if (element == 'E')
        color = 0xF0F0F0;
	else
		color = 0x0F000F;

    int x_pos, y_pos, pixel_pos;
    y_pos = 0;
    while (y_pos < 100)
	{
        x_pos = 0;
        while (x_pos < 100)
        {
            pixel_pos = (y_pos)  * data.img.line_len + x_pos * (data.img.bits_per_pixels / 8);
            *((unsigned int *)(data.img.img_pixels_ptr + pixel_pos)) = color;
            x_pos++;
        }
        y_pos++;
    }

    mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, x, y);
}

void	draw_map(mlx_data data , int x , int y)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	(void)x;
	(void)y;
	data.elem.map_y = 0;
	data.elem.P_posx = 0;
	data.elem.P_posy = 0;
	while (line)
	{
		i = 0;
		data.elem.map_x = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] == '1')
				create_element_image(data, '1', data.elem.map_x, data.elem.map_y);
			else if (line[i] == 'C')
				create_element_image(data, 'C', data.elem.map_x, data.elem.map_y);
			else if (line[i] == 'E')
				create_element_image(data, 'E', data.elem.map_x, data.elem.map_y);
			else if (line[i] == 'P')
			{
				data.elem.P_posy = 100;
				data.elem.P_posx = data.elem.map_x;
			}
			else
				create_element_image(data, '0', data.elem.map_x, data.elem.map_y);
			data.elem.map_x += 100;
			i++;
		}
		data.elem.map_y += 100;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	handle_input(int keysym, mlx_data *data)
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
		data->img.step_top_bottum += 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map(*data, data->img.step_right_left, data->img.step_top_bottum);
	}
	else if (keysym == 65362)
	{
		data->img.step_top_bottum -= 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map(*data, data->img.step_right_left, data->img.step_top_bottum);
	}
	else if (keysym == 65363)
	{
		data->img.step_right_left += 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map(*data, data->img.step_right_left, data->img.step_top_bottum);
	}
	else if (keysym == 65361)
	{
		data->img.step_right_left -= 100;
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_map(*data, data->img.step_right_left, data->img.step_top_bottum);
	}

	create_element_image(*data, 'P', data->elem.P_posx + data->img.step_right_left, data->elem.P_posy + data->img.step_top_bottum);	
	printf("the %d key has been pressed .\n", keysym);
	return (0);
}

int	err_free(char *line, int fd, char *err)
{
	free(line);
	close(fd);
	printf("%s\n", err);
	return (0);
}
int	check_T_B_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (i);
}
int	check_element_map()
{
	int		fd;
	char	*line;
	int		i;
	int		len;
	elem_data	elem;

	elem.P = 0;
	elem.E = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = check_T_B_wall(line);
	if (len == 0)
	{
		err_free(line, fd, "not all 1");
		return ( 0);
	}
	while (line)
	{
		i = 0;
		if (line[i] != '1')
		{
			err_free(line, fd, "wall not 1");
			return ( 0);
		}
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] == 'P')
				elem.P++;
			if (line[i] == 'E')
				elem.E++;
			i++;
		}
		if (line[i - 1] != '1')
		{
			err_free(line, fd, "wall not 1");
			return ( 0);
		}
		if (len != i)
		{
			err_free(line, fd, "len incorect");
			return (0);
		}
		if (line[i] == '\0' && check_T_B_wall(line) == 0)
		{
			err_free(line, fd, "not all 1");
			return ( 0);
		}
		HEIGHT += 100;
		free(line);
		line = get_next_line(fd);
	}
	if (elem.E != 1)
	{
		err_free(line, fd, "error in E");
		return ( 0);
	}
	if (elem.P != 1)
	{
		err_free(line, fd, "error in P");
		return ( 0);
	}
	free(line);
	close(fd);
	WIDTH = len * 100;
	return (1);
}

int	main(void)
{
	mlx_data	data;
	// int			x;
	// int			y;
	// int			pixel_pos;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	if(check_element_map() == 0)
		return (0);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "So Long");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	
	// data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	// data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
	// 		&data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);

	// y = 0;
	// while (y < HEIGHT)
	// {
	// 	x = 0;
	// 	while (x < WIDTH)
	// 	{
	// 		pixel_pos = y * data.img.line_len +  x * (data.img.bits_per_pixels / 8);
	// 		*((unsigned int *)(data.img.img_pixels_ptr + pixel_pos)) = 0xFF00FF;
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, 0, 0);

	data.img.step_right_left = 0;
	data.img.step_top_bottum = 0;
	draw_map(data, 0 , 0);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
