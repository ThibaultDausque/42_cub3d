/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:58:04 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/25 12:54:24 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		size;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	size = ft_strlen(src);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
