/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:34:03 by prosset           #+#    #+#             */
/*   Updated: 2025/04/18 14:08:52 by tdausque         ###   ########.fr       */
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
	int		hit;
	float	perpWallDist;
	int		side;

	data->ray.dirX = cosf(data->player.angle);
	data->ray.dirY = -sinf(data->player.angle);
	data->ray.x = data->player.x;
	data->ray.y = data->player.y;
	data->ray.mapX = (int)data->ray.x;
	data->ray.mapY = (int)data->ray.y;
	hit = 0;
	deltaDist(data);
	sideDist(data);
	//printf("sideDistX : %f, sideDistY : %f\n", data->ray.sdistX, data->ray.sdistY);
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
		perpWallDist = (data->ray.sdistX - data->ray.ddistX) * cosf(data->player.angle - M_PI / 2);
	else
		perpWallDist = (data->ray.sdistY - data->ray.ddistY) * cosf(data->player.angle - M_PI / 2);

	//printf("%f\n", perpWallDist);
	int	lineheight = (int)(HEIGHT / perpWallDist);
	//printf("%d\n", lineheight);
	int drawStart = -lineheight / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineheight / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;

	int i = 0;
	while (drawStart + i < drawEnd)
	{
		my_mlx_pixel_put(img, x, drawStart + i, 0x00FF0000);
		mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
		i++;
	}
	i = 0;
	while (i < drawStart)
	{
		my_mlx_pixel_put(img, x, i, 0x0000FF00);
		mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
		i++;
	}
	i = 0;
	while (drawEnd + i < HEIGHT)
	{
		my_mlx_pixel_put(img, x, drawEnd + i, 0x000000FF);
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

void	textures(t_data *data, float perpWallDist, int side)
{
	int		texNum;
	float	wallX;
	int		texX;

	texNum = data->map[data->ray.mapY][data->ray.mapX] - 1;
	if (side == 0)
		wallX = data->player.y + perpWallDist * data->ray.dirY;
	else
		wallX = data->player.x + perpWallDist * data->ray.dirX;
	wallX -= (int)wallX;

	texX = (int)(wallX * (double)data->textW);
	if (side == 0 && data->ray.dirX > 0)
		texX = data->textW - texX - 1;
	if (side == 1 && data->ray.dirY < 0)
		texX = data->textW - texX - 1;
}