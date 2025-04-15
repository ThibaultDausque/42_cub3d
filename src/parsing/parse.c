/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:40:57 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/15 16:05:56 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map_line(char *filename)
{
	int		fd;
	int		count;
	char	*buff;

	fd = open(filename, O_RDONLY);
	count = 0;
	buff = get_next_line(fd);
	while (buff)
	{
		count++;
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	return (count);
}

char	**map_tab(char *filename)
{
	int		fd;
	char	*buff;
	char	**tab;
	int		map_size;
	int		count;
	int		i;

	fd = open(filename, O_RDONLY);
	count = 0;
	map_size = count_map_line(filename) - 8;
	tab = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (!tab)
		return (NULL);
	buff = get_next_line(fd);
	while (count < 8)
	{
		free(buff);
		buff = get_next_line(fd);
		count++;
	}
	i = 0;
	while (buff)
	{
		tab[i++] = ft_strdup(buff);
		free(buff);
		buff = get_next_line(fd);
	}
	tab[i] = NULL;
	return (tab);
}


int	main(void)
{
	char	*filename = "maps/test.cub";
	s_map	*map;
	char	**tab;
	int		i;

	map = (s_map *)malloc(sizeof(s_map));
	if (!map)
		return (0);
	map->filename = "maps/test.cub";
	map->tab = map_tab(map->filename);
	map->width = max_width(map->tab);
	map->height = max_height(map->tab);
	printf("height: %d\n", max_height(map->tab));
	printf("width: %d\n", max_width(map->tab));
	printf("nb of lines: %d\n", count_map_line(filename));
	printf("---CUB3D MAP---\n");
	tab = map_tab(filename);
	i = 0;
	while (tab[i])
		printf("%s", tab[i++]);
	printf("\nIs the good extension ?\n");
	if (!cub_ext(filename))
		printf("error: absolutely not.\n");
	else
		printf("Yeah that's okay.\n");
	flood_fill(map, 10, 2);
	return (0);
}