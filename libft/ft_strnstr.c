/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:36:25 by hwahmane          #+#    #+#             */
/*   Updated: 2025/01/13 21:00:51 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] && haystack[i + k] == needle[k] && needle[k]
			&& (len > i + k))
			k++;
		if (needle[k] == '\0')
			return ((char *)&(haystack[i]));
		i++;
	}
	return (NULL);
}
