/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:14:21 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/18 11:56:51 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    enemy_link_array(t_mlx_data *data, int j, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    i = 0;
    while(i <= 5)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.enemy[j][i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.enemy[j][i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    player_link_array(t_mlx_data *data, int j, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    i = 0;
    while(i <= 5)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.player[j][i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.player[j][i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    attack_link_array(t_mlx_data *data, int j, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    i = 0;
    while(i <= 8)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.attack[j][i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.attack[j][i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    death_link_array(t_mlx_data *data, int j, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    i = 0;
    while(i <= 8)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.death[j][i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.death[j][i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}

void    home_link_array(t_mlx_data *data, int j, char *link)
{
    int i;
    char *number;
    char *path;
    char *full_path;

    i = 0;
    while(i <= 5)
    {
        number = ft_itoa(i);
        path = ft_strjoin(link, number);
        full_path = ft_strjoin(path, ".xpm");
        data->path.home[j][i] = mlx_xpm_file_to_image(data->mlx,
			full_path,
			&data->img.img_width,
			&data->img.img_height);
        if (!data->path.home[j][i])
            free_destroy(data, 1);
        free(number);
        free(path);
        free(full_path);
        i++;
    }
}
