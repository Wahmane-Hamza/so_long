/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:18:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/11 22:07:41 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bits_per_pixels / 8));
// 	*(unsigned int*)dst = color;
// }

// int mouse_hook(int button, int x, int y, t_mlx_data *data)
// {
//     (void)x;
//     (void)y;
//     int i;
//     int j;

//     printf("Mouse button clicked: %d\n", button);
//     data->img.color = 0x0000F000 + button * 50;
//     i = 0;
//     while (i < 540)
//     {
//         j = 0;
//         while (j < 960)
//         {
//             my_mlx_pixel_put(data, j, i, data->img.color);
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
//     return (0);
// }

// int main()
// {
//     t_mlx_data data;
//     int i;
//     int j;

//     data.mlx = mlx_init();
//     data.mlx_win = mlx_new_window(data.mlx, 960, 540, "so_long");

//     data.img.img_ptr = mlx_new_image(data.mlx, 960, 540);
//     data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);

//     data.img.color = 0x00FF0000;
//     i = 0;
//     while (i < 540)
//     {
//         j = 0;
//         while (j < 960)
//         {
//             my_mlx_pixel_put(&data, j, i, data.img.color);
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, 0, 0);
        
//     mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
//     mlx_loop(data.mlx);
// }

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "images/gound_wall/ground.xpm";
	int		img_width;
	int		img_height;
    int i;
    int j;

	mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 800, "so_long");

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

    printf("%-d--%d\n",img_height, img_width);
    i = 0;
	while (i < 800 / img_height)
	{
		j = 0;
		while (j < 800 / img_width)
		{
			mlx_put_image_to_window(mlx, win, img, j * img_width, i * img_height);
			j++;
		}
		i++;
	}

    mlx_loop(mlx);
}