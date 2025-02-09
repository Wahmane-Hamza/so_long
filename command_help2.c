/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_help2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:39:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/09 18:53:49 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p_pos(char *line, t_mlx_data *data, int i)
{
	int	j;

	j = 0;
	while (line[j++])
	{
		if (line[j] == 'P')
		{
			data->elem.p_posx = j;
			data->elem.p_posy = i;
		}
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	*map_len(t_mlx_data *data)
{
	int		fd;
	char	*line;

	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	data->map.map_x_len = strlen(line) - 1;
	data->map.map_y_len = 0;
	while (line)
	{
		data->map.map_y_len++;
		free(line);
		line = get_next_line(fd);
	}
	return (data);
}

char	**map_to_array(t_mlx_data *data, char **av)
{
	int		fd;
	int		i;
	char	*line;

	data = map_len(data);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("open faild", NULL, -1, 1);
	line = get_next_line(fd);
	if (!line)
		error_exit(NULL, NULL, -1, 0);
	data->map.array = malloc((data->map.map_y_len + 1) * sizeof(char *));
	i = 0;
	while (i < data->map.map_y_len)
	{
		data->map.array[i] = ft_strdup(line);
		find_p_pos(line, data, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.array[i] = NULL;
	return (data->map.array);
}
