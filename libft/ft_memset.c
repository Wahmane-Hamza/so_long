/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmane <wahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:02:01 by wahmane           #+#    #+#             */
/*   Updated: 2025/02/15 15:02:13 by wahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*ptr;
	unsigned char	uc;
	size_t			i;

	ptr = str;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
		ptr[i++] = uc;
	return (str);
}