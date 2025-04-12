/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:09:12 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/24 10:48:16 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
