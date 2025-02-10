/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:15:00 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 20:05:07 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr2(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup2(char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(ft_strlen2(s1) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup2(s1));
	if (!s1 && s2)
		return (ft_strdup2(s2));
	if (!s1 && !s2)
		return (ft_strdup2(""));
	size = ft_strlen2(s1) + ft_strlen2(s2) + 1;
	dst = malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

int	before_n_stack(char *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	return (i);
}

int	after_n_stack(char *stack, int i)
{
	int	j;

	j = 0;
	while (stack[i])
	{
		i++;
		j++;
	}
	return (j);
}
