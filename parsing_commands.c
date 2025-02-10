/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:38:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 18:37:24 by hwahmane         ###   ########.fr       */
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
			error_exit("error in E", line, fd, NULL);
		if (data->elem.p != 1)
			error_exit("error in P", line, fd, NULL);
		if (data->elem.c == 0)
			error_exit("error in C", line, fd, NULL);
	}
	return (add_check);
}

void	*check_element_map(char *line, t_mlx_data *data, int fd, int len)
{
	int	i;

	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
			error_exit("Error: empty line", line, fd, NULL);
		check_line_char(line, fd);
		i = 0;
		if (line[i] == '\0' && line[i + 1] == '\n')
			error_exit("Error: empty line", line, fd, NULL);
		if (line[i] != '1')
			error_exit("Error: The start not wall", line, fd, NULL);
		i = check_caracters(line, data, i, -1);
		if (line[i - 1] != '1')
			error_exit("Error: The end not wall", line, fd, NULL);
		if (len != i)
			error_exit("Error: len incorect", line, fd, NULL);
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

	data->elem.p = 0;
	data->elem.e = 0;
	data->elem.c = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: open faild", NULL, -1, NULL);
	line = get_next_line(fd);
	if (!line)
		error_exit("Error: get next line faild", NULL, fd, NULL);
	if (line[0] == '\n')
		error_exit("Error: empty line", line, fd, NULL);
	check_line_char(line, fd);
	len = check_t_b_wall(line);
	if (len == 0)
		error_exit("Error: The wall not all 1", line, fd, NULL);
	line = check_element_map(line, data, fd, len);
	check_caracters(line, data, 1, fd);
	free(line);
	close(fd);
	return (1);
}
