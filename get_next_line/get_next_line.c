/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:14:53 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 20:04:47 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*new_n(char *stack)
{
	int		i;
	int		len_before_n;
	int		len_after_n;
	char	*cup;

	len_before_n = before_n_stack(stack);
	if (stack[len_before_n] == '\0')
		return (free(stack), NULL);
	if (stack[len_before_n + 1] != '\0')
	{
		len_after_n = after_n_stack(stack, len_before_n + 1);
		cup = malloc(len_after_n + 1);
		if (!cup)
			return (free(stack), NULL);
		i = 0;
		while (stack[len_before_n + 1])
		{
			len_before_n++;
			cup[i] = stack[len_before_n];
			i++;
		}
		cup[i] = '\0';
		return (free(stack), cup);
	}
	return (free(stack), NULL);
}

char	*the_line(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_n(char *stack, int fd)
{
	ssize_t	i;
	char	*buffer;
	char	*temp;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr2(stack, '\n') != 1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			if (i == 0)
				return (free(buffer), stack);
			return (free(buffer), NULL);
		}
		buffer[i] = '\0';
		temp = stack;
		stack = ft_strjoin2(stack, buffer);
		free(temp);
		if (!stack)
			return (free(buffer), free(stack), NULL);
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	stack[fd] = get_n(stack[fd], fd);
	if (!stack[fd])
		return (free(stack[fd]), NULL);
	line = the_line(stack[fd]);
	stack[fd] = new_n(stack[fd]);
	return (line);
}
