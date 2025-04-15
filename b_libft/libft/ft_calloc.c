/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:27:23 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/23 16:05:01 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (size > INT_MAX || nmemb > INT_MAX)
		return (0);
	if (size * nmemb > INT_MAX)
		return (0);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	str = malloc(size * nmemb);
	if (!str)
		return (0);
	while (i != (size * nmemb))
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}
