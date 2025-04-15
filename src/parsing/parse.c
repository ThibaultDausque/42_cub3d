/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:40:57 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/15 13:58:20 by tdausque         ###   ########.fr       */
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

int	map_is_enclosed(char **map, char *filename)
{
	int		i;
	int		j;
	int		map_len;

	map_len = count_map_line(filename) - 8;
	j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (map[i][j] && i < map_len - 1)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][0] != '1')
				return (0);
			j++;
		}
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

int	main(void)
{
	char	*filename = "maps/test.cub";
	char	**tab;
	int		i;

	printf("nb of lines: %d\n", count_map_line(filename));
	printf("---CUB3D MAP---\n");
	tab = map_tab(filename);
	i = 0;
	while (tab[i])
		printf("%s", tab[i++]);
	printf("\nIs the map enclosed ?\n");
	if (!map_is_enclosed(tab, filename))
		printf("error: absolutely not.\n");
	else
		printf("Yeah that's okay.");
	printf("\nIs the good extension ?\n");
	if (!cub_ext(filename))
		printf("error: absolutely not.\n");
	else
		printf("Yeah that's okay.");
	return (0);
}