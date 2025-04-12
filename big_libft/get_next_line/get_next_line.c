/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:07:58 by tdausque          #+#    #+#             */
/*   Updated: 2024/11/24 11:07:13 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *buff, char *stash)
{
	int		b_reads;

	b_reads = 1;
	while (b_reads > 0 && !ft_strchr(buff, '\n'))
	{
		b_reads = read(fd, buff, BUFFER_SIZE);
		if (b_reads < 0 || (!b_reads && !stash[0]))
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[b_reads] = 0;
		stash = ft_strjoin(stash, buff);
		if (!stash)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (stash);
}

char	*extract_line(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line));
	if (line[i] == '\n')
		line[++i] = '\0';
	return (tmp);
}

char	*init_stash(char *stash)
{
	if (stash == NULL)
	{
		stash = malloc(1);
		if (!stash)
			return (0);
		stash[0] = '\0';
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = init_stash(stash);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free(stash);
		return (NULL);
	}
	buff[0] = '\0';
	line = fill_stash(fd, buff, stash);
	if (!line)
	{
		stash = NULL;
		return (NULL);
	}
	stash = extract_line(line);
	return (line);
}
