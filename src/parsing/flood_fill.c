/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:58:54 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/17 10:08:50 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width
		|| y >= map->height)
	{
		printf("Error: map isn't closed.\n");
		exit(EXIT_FAILURE);
	}

	if (map->tab[y][x] == 'o' || map->tab[y][x] == '1')
		return ;

	map->tab[y][x] = 'o';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}