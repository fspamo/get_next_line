/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:15:23 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/19 15:39:56 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*next_lining(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*read_as_buffer(int fd, char *stash)
{
	char	*buffer;
	char	*holder;
	int		bytes_to_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_to_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_to_read != 0)
	{
		bytes_to_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_to_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_to_read] = '\0';
		holder = ft_strjoin(stash, buffer);
		free(stash);
		stash = holder;
	}
	free(buffer);
	return (stash);
}

static char	*clean_stash(char *stash)
{
	int			i;
	int			j;
	char		*new;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i += (stash[i] == '\n');
	if (!stash[i])
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		free(stash);
		return (new);
	}
	new = malloc(ft_strlen(stash) - i + 1);
	if (!new)
		return (NULL);
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	return (free(stash), new);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_as_buffer(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
		return (NULL);
	line = next_lining(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
