/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:38:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/24 12:35:47 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_exit(char *message, char *line, int fd, char **array)
{
	if (line)
		free(line);
	if (fd != -1)
		close(fd);
	if (array)
		free_map(array);
	if (message)
		write(2, message, strlen(message));
	exit(1);
}

int	check_t_b_wall(char *line)
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

int	check_caracters(char *line, t_mlx_data *data, int add_check, int fd)
{
	if (add_check == 0)
	{
		while (line[add_check] != '\n' && line[add_check] != '\0')
		{
			if (line[add_check] == 'P')
				data->elem.p++;
			if (line[add_check] == 'E')
				data->elem.e++;
			if (line[add_check] == 'C')
				data->elem.c++;
			add_check++;
		}
	}
	else if (add_check == 1)
	{
		if (data->elem.e != 1)
			error_exit("Error\nThe map must contain a Exit(E)", line, fd, NULL);
		if (data->elem.p != 1)
			error_exit("Error\nThe map must contain Player(P)", line, fd, NULL);
		if (data->elem.c == 0)
			error_exit("Error\nThe map must contain a Coin(C)", line, fd, NULL);
	}
	return (add_check);
}

void	*check_element_map(char *line, t_mlx_data *data, int fd, int len)
{
	int	i;

	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
			error_exit("Error\nempty line", line, fd, NULL);
		check_line_char(line, fd);
		i = 0;
		if (line[i] == '\0' && line[i + 1] == '\n')
			error_exit("Error\nempty line", line, fd, NULL);
		if (line[i] != '1')
			error_exit("Error\nThe start not wall", line, fd, NULL);
		i = check_caracters(line, data, i, -1);
		if (line[i - 1] != '1')
			error_exit("Error\nThe end not wall", line, fd, NULL);
		if (len != i)
			error_exit("Error\nLen incorect", line, fd, NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	check_all(char **av, t_mlx_data *data)
{
	int		fd;
	char	*line;
	int		len;

	set_zero(data);
	data->map.render = 1;
	check_map_extention(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error\nopen faild", NULL, -1, NULL);
	line = get_next_line(fd);
	if (!line)
		error_exit("Error\nEmpty map", NULL, fd, NULL);
	if (line[0] == '\n')
		error_exit("Error\nEmpty line", line, fd, NULL);
	check_line_char(line, fd);
	len = check_t_b_wall(line);
	if (len == 0)
		error_exit("Error\nThe wall not all 1", line, fd, NULL);
	line = check_element_map(line, data, fd, len);
	check_caracters(line, data, 1, fd);
	free(line);
	close(fd);
	return (1);
}
