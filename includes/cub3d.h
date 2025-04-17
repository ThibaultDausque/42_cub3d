/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:40:11 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/17 16:00:42 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define PIXEL 64
# define WIDTH 320
# define HEIGHT 200

typedef struct s_map
{
	char	**tab;
	char	*filename;
	int		width;
	int		height;
} t_map;


typedef struct s_player
{
	float	x;
	float	y;
} t_player;

typedef struct s_ray
{
	float	x;
	float	y;
	float	dirX;
	float	dirY;
	float	ddistX;
	float	ddistY;
	float	sdistX;
	float	sdistY;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
} t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_ray		ray;
} t_data;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

//////PARSING//////
int		count_map_line(char *filename);
int		cub_ext(char *filename);
void	flood_fill(t_map *map, int x, int y);
char	**map_tab(char *filename);

//////UTILS//////
int	ft_strcmp(const char *s1, const char *s2);
int	max_width(char **map);
int	max_height(char **map);

/*    create.c    */
void	create_data(t_data *data, char **av);

/*    free.c    */
void	ft_free_tab(char **tab);
void	ft_free_all(t_data *data);

/*    raycasting.c    */
void	raycasting(t_data *data, int x, t_img *img);
int		vertical_lines(t_data *data);
int		horizont_lines(t_data *data);
void	deltaDist(t_data *data);
void	sideDist(t_data *data);

#endif
