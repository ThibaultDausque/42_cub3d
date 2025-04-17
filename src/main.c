/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:39:11 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/17 16:00:46 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(int ac, char **av)
// {
// 	t_map	*map;
// 	char	**tab;
// 	int		i;
// 	(void) ac;

// 	map = (t_map *)malloc(sizeof(t_map));
// 	if (!map)
// 		return (0);
// 	map->filename = av[1];
// 	map->tab = map_tab(map->filename);
// 	map->width = max_width(map->tab);
// 	map->height = max_height(map->tab);
// 	printf("height: %d\n", max_height(map->tab));
// 	printf("width: %d\n", max_width(map->tab));
// 	printf("nb of lines: %d\n", count_map_line(map->filename));
// 	printf("---CUB3D MAP---\n");
// 	tab = map_tab(map->filename);
// 	i = 0;
// 	while (tab[i])
// 		printf("%s", tab[i++]);
// 	printf("\nIs the good extension ?\n");
// 	if (!cub_ext(map->filename))
// 		printf("error: absolutely not.\n");
// 	else
// 		printf("Yeah that's okay.\n");
// 	flood_fill(map, 10, 2);
// 	free(map);
// 	return (0);
// }

int	ft_close(int keycode, t_data *data);
int	ft_redcross(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;
	t_img	img;
	int		x;

	(void)ac;
	create_data(&data, av);
	int i = 0;
	while (data.map.tab[i])
	{
		printf("%s\n", data.map.tab[i]);
		i++;
	}
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		ft_printf("Error : mlx_init failure\n");
		ft_free_tab(data.map.tab);
		return (0);
	}
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3d");
	mlx_hook(data.win, 17, 1L << 2, ft_redcross, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_close, &data);
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < WIDTH)
	{
		raycasting(&data, x, &img);
		x++;
	}
	mlx_loop(data.mlx);
	ft_free_all(&data);
}

int	ft_close(int keycode, t_data *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx);
	return (0);
}

int	ft_redcross(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}
