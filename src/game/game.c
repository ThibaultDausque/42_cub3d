/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:15:41 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/18 13:46:07 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(t_data *data, float dx, float dy)
{
	float		x;
	float		y;

	x = data->player.x + dx;
	y = data->player.y + dy;

	if (data->map.tab[(int)y][(int)x] == '1')
		return (0);
	data->player.x = x;
	data->player.y = y;
	return (1);
}

void	key_handler(int keycode, t_data *data)
{
	t_img	img;
	int		x;

	x = 0;
	if (keycode == 'w')
		x = move_player(data, 0.0, -0.5);
	else if (keycode == 's')
		x = move_player(data, 0.0, 0.5);
	else if (keycode == 'd')
		x = move_player(data, 0.5, 0.0);
	else if (keycode == 'a')
		x = move_player(data, -0.5, 0.0);
	if (!x)
		return ;
	img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < WIDTH)
	{
		data->player.angle = M_PI / 6 + M_PI / 2 - (x * M_PI / 3) / WIDTH;
		raycasting(data, x, &img);
		x++;
	}
}