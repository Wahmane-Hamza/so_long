/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:41 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/13 15:41:16 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"



void    stop_animation(t_mlx_data *data, int i, char *link)
{
    char	*path;
	char	*number;
	char	*full_path;

	number = ft_itoa(i + 1);
	path = ft_strjoin(link, number);
	full_path = ft_strjoin(path, ".xpm");
	free(number);
	free(path);
    data->img.map_player_front = mlx_xpm_file_to_image(data->mlx,
                full_path, &data->img.img_width,
                &data->img.img_height);

	free(full_path);
}
