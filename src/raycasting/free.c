/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:37:14 by prosset           #+#    #+#             */
/*   Updated: 2025/04/14 14:56:30 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_all(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	//ft_free_sprites(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_tab(data->map.tab);
}