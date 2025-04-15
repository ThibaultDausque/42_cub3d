/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:40:42 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/15 13:00:08 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_ext(char *filename)
{
	int		i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			break ;
		i++;
	}
	if (filename[i] == '\0')
		return (0);
	if (ft_strcmp(filename + i, ".cub") == 0)
		return (1);
	return (0);
}