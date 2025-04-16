/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:34:03 by prosset           #+#    #+#             */
/*   Updated: 2025/04/15 15:47:24 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	raycasting(t_data *data)
{
	//float	planeX = 0;
	//float	planeY = 0.6;
	int		hit;
	float	length;
	float	X;
	float	Y;
	float	proj_length;
	t_img	img;

	data->ray.dirX = 0;
	data->ray.dirY = -1;
	data->ray.x = data->player.x;
	data->ray.y = data->player.y;
	hit = 0;
	while (!hit && data->ray.y > 0 && data->ray.x > 0)
	{
		data->ray.x += data->ray.dirX * 0.01;
		data->ray.y += data->ray.dirY * 0.01;
		if (horizont_lines(data))
			hit = 1;
		if (vertical_lines(data))
			hit = 1;
	}
	X = data->player.x - data->ray.x;
	Y = data->player.y - data->ray.y;
	length = hypot(X, Y) * cos(0) * 64;
	if (length == 0)
		proj_length = HEIGHT;
	else
		proj_length = (64 / length) * 277;
	if (proj_length > HEIGHT)
		proj_length = HEIGHT;
	
	printf("%f %f\n", length, proj_length);
	
	img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int i = 0;
	while (i < (int)proj_length)
	{
		my_mlx_pixel_put(&img, WIDTH / 2, i + (HEIGHT / 2) - proj_length / 2, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
		i++;
	}
}

int	horizont_lines(t_data *data)
{
	int	i;
	int	j;
	
	i = (int)(data->ray.y);
	j = (int)(data->ray.x);
	if (data->map.tab[i][j] == '1')
	{
		printf("oui\n");
		return (1);
	}
	return (0);
}

int	vertical_lines(t_data *data)
{
	int	i;
	int	j;
	
	i = (int)(data->ray.y);
	j = (int)(data->ray.x);
	if (data->map.tab[i][j - 1] == 1)
			return (1);
	return (0);
}
