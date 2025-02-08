/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:38:32 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/08 14:02:43 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (1);
}
