/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwahmane <hwahmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:52 by hwahmane          #+#    #+#             */
/*   Updated: 2025/02/10 18:50:02 by hwahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		if (check_all(av, &data) == 0)
			return (0);
		data.map.array = map_to_array(&data, av);
		if (flood_fill(&data) == 0)
			error_exit("Error: The wall blocks the player.\n", NULL, -1, NULL);
		free_map(data.map.array);
		return (0);
	}
	else
		error_exit("Bad argement:./so_long map\n", NULL, -1, NULL);
}
