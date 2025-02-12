/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_commands2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:39:46 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/12 17:22:22 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_p_pos(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.array[i])
	{
		j = 0;
		while (data->map.array[i][j])
		{
			if (data->map.array[i][j] == 'P')
			{
				data->elem.p_posx = j;
				data->elem.p_posy = i;
			}
			j++;
		}
		i++;
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

void	*map_len(t_mlx_data *data, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	data->map.map_x_len = strlen(line) - 1;
	data->map.map_y_len = 0;
	while (line)
	{
		data->map.map_y_len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (data);
}

char	**map_to_array(t_mlx_data *data, char **av)
{
	int		fd;
	int		i;
	char	*line;

	data = map_len(data, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: open faild", NULL, -1, NULL);
	line = get_next_line(fd);
	if (!line)
		error_exit("Error: get next line faild", NULL, fd, NULL);
	data->map.array = malloc((data->map.map_y_len + 1) * sizeof(char *));
	i = 0;
	while (i < data->map.map_y_len)
	{
		data->map.array[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.array[i] = NULL;
	if (check_t_b_wall(data->map.array[i - 1]) == 0)
		error_exit("Error: The wall not all 1", line, fd, data->map.array);
	return (close(fd), data->map.array);
}

void	check_line_char(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'P' || line[i] == 'C' || line[i] == 'E' || line[i] == '1'
			|| line[i] == '0')
			i++;
		else
			error_exit("Error: Invalid char in the map", line, fd, NULL);
	}
}
