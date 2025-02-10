/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:02 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 20:16:59 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extention(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
		{
			if (ft_strncmp("ber", &av[1][i + 1], ft_strlen(&av[1][i + 1])) != 0
				|| ft_strncmp("ber", &av[1][i + 1], 3) != 0)
				error_exit("extention not (.ber)", NULL, -1, NULL);
		}
		i++;
	}
}
