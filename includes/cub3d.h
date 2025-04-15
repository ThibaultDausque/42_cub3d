/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:40:11 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/15 15:44:39 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct t_map
{
	char	**tab;
	char	*filename;
	int		width;
	int		height;
} s_map;

//////PARSING//////
int		count_map_line(char *filename);
int		cub_ext(char *filename);
void	flood_fill(s_map *map, int x, int y);

//////UTILS//////
int	ft_strcmp(const char *s1, const char *s2);
int	max_width(char **map);
int	max_height(char **map);

#endif
