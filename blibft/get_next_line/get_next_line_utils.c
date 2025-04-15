/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:24:15 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/15 10:22:04 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	while (s && *s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

char	*gnl_strdup(char *src)
{
	int		size;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	size = gnl_strlen(src);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = gnl_strlen(s1) + gnl_strlen(s2);
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[gnl_strlen(s1) + i] = s2[i];
		i++;
	}
	str[gnl_strlen(s1) + i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (start >= gnl_strlen(s))
		return (gnl_strdup(""));
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[j] != '\0' && i < len)
	{
		str[i] = s[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
