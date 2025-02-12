/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:27:48 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/12 17:22:27 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_duplicate(t_mlx_data *data)
{
	char	**cpy_array;
	int		i;

	cpy_array = malloc((data->map.map_y_len + 1) * sizeof(char *));
	i = 0;
	while (i < data->map.map_y_len)
	{
		cpy_array[i] = ft_strdup(data->map.array[i]);
		i++;
	}
	cpy_array[i] = NULL;
	return (cpy_array);
}

int	find_c_e(char **map, char find)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (find == 'C')
				if (map[i][j] == 'C')
					return (0);
			if (find == 'E')
				if (map[i][j] == 'E')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**flood_fill_player(int x, int y, char **map)
{
	if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == '0')
	{
		map[y][x] = 'X';
		flood_fill_player(x + 1, y, map);
		flood_fill_player(x - 1, y, map);
		flood_fill_player(x, y + 1, map);
		flood_fill_player(x, y - 1, map);
	}
	return (map);
}

char	**flood_fill_exit(int x, int y, char **map)
{
	if (map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == '0'
		|| map[y][x] == 'P')
	{
		map[y][x] = 'Z';
		flood_fill_exit(x + 1, y, map);
		flood_fill_exit(x - 1, y, map);
		flood_fill_exit(x, y + 1, map);
		flood_fill_exit(x, y - 1, map);
	}
	return (map);
}

int	flood_fill(t_mlx_data *data)
{
	char	**cpy_array;

	find_p_pos(data);
	cpy_array = map_duplicate(data);
	flood_fill_player(data->elem.p_posx, data->elem.p_posy, cpy_array);
	if (find_c_e(cpy_array, 'C') == 0)
	{
		free_map(cpy_array);
		free_map(data->map.array);
		return (0);
	}
	free_map(cpy_array);
	cpy_array = map_duplicate(data);
	flood_fill_exit(data->elem.p_posx, data->elem.p_posy, cpy_array);
	if (find_c_e(cpy_array, 'E') == 0)
	{
		free_map(cpy_array);
		free_map(data->map.array);
		return (0);
	}
	free_map(cpy_array);
	return (1);
}
