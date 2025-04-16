/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:39:11 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/16 09:51:11 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	s_map	*map;
	char	**tab;
	int		i;
	(void) ac;

	map = (s_map *)malloc(sizeof(s_map));
	if (!map)
		return (0);
	map->filename = av[1];
	map->tab = map_tab(map->filename);
	map->width = max_width(map->tab);
	map->height = max_height(map->tab);
	printf("height: %d\n", max_height(map->tab));
	printf("width: %d\n", max_width(map->tab));
	printf("nb of lines: %d\n", count_map_line(map->filename));
	printf("---CUB3D MAP---\n");
	tab = map_tab(map->filename);
	i = 0;
	while (tab[i])
		printf("%s", tab[i++]);
	printf("\nIs the good extension ?\n");
	if (!cub_ext(map->filename))
		printf("error: absolutely not.\n");
	else
		printf("Yeah that's okay.\n");
	flood_fill(map, 10, 2);
	free(map);
	return (0);
}
