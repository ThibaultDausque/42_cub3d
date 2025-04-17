/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:34:03 by prosset           #+#    #+#             */
/*   Updated: 2025/04/17 16:01:41 by tdausque         ###   ########.fr       */
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

void	raycasting(t_data *data, int x, t_img *img)
{
	float	planeX = 0;
	float	planeY = 0.6;
	int		hit;
	float	perpWallDist;
	int		side;
	float	cameraX;

	data->ray.dirX = 0;
	data->ray.dirY = -1;
	cameraX = 2 * x / WIDTH - 1;
	data->ray.dirX = data->ray.dirX + planeX * cameraX;
	data->ray.dirY = data->ray.dirY + planeY * cameraX;
	data->ray.x = data->player.x;
	data->ray.y = data->player.y;
	data->ray.mapX = (int)data->ray.x;
	data->ray.mapY = (int)data->ray.y;
	hit = 0;
	deltaDist(data);
	sideDist(data);
	while (!hit)
	{
		if (data->ray.sdistX < data->ray.sdistY)
		{
			data->ray.sdistX += data->ray.ddistX;
			data->ray.mapX += data->ray.stepX;
			side = 0;
		}
		else
		{
			data->ray.sdistY += data->ray.ddistY;
			data->ray.mapY += data->ray.stepY;
			side = 1;
		}
		if (data->map.tab[data->ray.mapY][data->ray.mapX] == '1')
			hit = 1;
	}
	if (side == 0)
		perpWallDist = (data->ray.sdistX - data->ray.ddistX);
	else
		perpWallDist = (data->ray.sdistY - data->ray.ddistY);

	printf("%f\n", perpWallDist);
	int	lineheight = (int)(HEIGHT / perpWallDist);
	printf("%d\n", lineheight);
	int drawStart = -lineheight / 2 + HEIGHT / 2;
    if(drawStart < 0)
		drawStart = 0;
    int drawEnd = lineheight / 2 + HEIGHT / 2;
    if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	// X = data->player.x - data->ray.x;
	// Y = data->player.y - data->ray.y;
	// length = hypot(X, Y) * cos(0) * 64;
	// if (length == 0)
	// 	proj_length = HEIGHT;
	// else
	// 	proj_length = (64 / length) * 277;
	// if (proj_length > HEIGHT)
	// 	proj_length = HEIGHT;

	// printf("%f %f\n", length, proj_length);


	int i = 0;
	while (drawStart + i < drawEnd)
	{
		my_mlx_pixel_put(img, x, drawStart + i, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
		i++;
	}
}

void	deltaDist(t_data *data)
{
	if (data->ray.dirX == 0)
		data->ray.ddistX = 2147483647.0;
	else
		data->ray.ddistX = fabsf(1 / data->ray.dirX);

	if (data->ray.dirY == 0)
		data->ray.ddistY = 2147483647.0;
	else
		data->ray.ddistY = fabsf(1 / data->ray.dirY);

}

void	sideDist(t_data *data)
{
	if (data->ray.dirX < 0)
	{
		data->ray.sdistX = (data->player.x - data->ray.mapX) * data->ray.ddistX;
		data->ray.stepX = -1;
	}
	else
	{
		data->ray.sdistX = (data->ray.mapX + 1.0 - data->player.x) * data->ray.ddistX;
		data->ray.stepX = 1;
	}
	if (data->ray.dirY < 0)
	{
		data->ray.sdistY = (data->player.y - data->ray.mapY) * data->ray.ddistY;
		data->ray.stepY = -1;
	}
	else
	{
		data->ray.sdistY = (data->ray.mapY + 1.0 - data->player.y) * data->ray.ddistY;
		data->ray.stepY = 1;
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
