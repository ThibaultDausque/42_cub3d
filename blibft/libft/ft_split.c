/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:11:08 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/23 10:05:18 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *str, char sep)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			j++;
		while (str[i] != '\0' && str[i] != sep)
			i++;
	}
	return (j);
}

static char	*dup_word(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static void	split_word(char *s, char c, char **str)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = -1;
	k = 0;
	while (k <= ft_strlen(s))
	{
		if (s[k] != c && j == -1)
			j = k;
		else if ((s[k] == c || s[k] == '\0') && j >= 0)
		{
			str[i++] = dup_word(s, j, k);
			j = -1;
		}
		k++;
	}
	str[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*ss;

	ss = (char *)s;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (0);
	split_word(ss, c, str);
	return (str);
}
