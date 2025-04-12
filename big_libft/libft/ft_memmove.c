/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:25:03 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/20 18:03:39 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (d);
}
