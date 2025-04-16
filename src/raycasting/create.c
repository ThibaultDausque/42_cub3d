/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosset <prosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:19:28 by prosset           #+#    #+#             */
/*   Updated: 2025/04/15 14:28:27 by prosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**fill_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
				tab[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (tab);
}

char	**get_map(int fd)
{
	char	**tab;
	int		i;

	i = 1;
	tab = ft_calloc(sizeof(char *), 10000 / PIXEL);
	if (!tab)
		return (0);
	tab[0] = get_next_line(fd);
	if (!tab[0])
		return (0);
	while (ft_is_endl(tab[i - 1]))
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (0);
		}
		i++;
	}
	tab = fill_tab(tab);
	return (tab);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (is_player(data->map.tab[i][j]))
			{
				data->player.x = j + 0.5;
				data->player.y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	create_data(t_data *data, int fd)
{
	data->map.tab = get_map(fd);
	player_pos(data);
}