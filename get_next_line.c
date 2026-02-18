/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:15:23 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 22:38:35 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
// #include <stdlib.h>
#include <fcntl.h>

char *next_lining(char *stash)
{
    int		i;
    int 	j;
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
        return NULL;
    while (j < i)
    {
        line[j] = stash[j];
        j++;
    }
    if (stash[i] == '\n')
    {
        line[j] = '\n';
        j++;
    }

    line[j] = '\0';
    return line;
}

char	*read_as_buffer(int fd, char *stash)
{
	char	*buffer;
	size_t 	bytes_to_read;
	int i;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	bytes_to_read = read(fd, buffer, BUFFER_SIZE);
	//strjoin
	if (!stash)
		stash = malloc(bytes_to_read + 1);
	while (i < bytes_to_read)
	{
		stash[i] = buffer[i];
		i++;
	}
	return (stash);
}

char	*clean_stash(char *stash)
{
	int 	i;
	int 	j;
	char	*new;
	
	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	new = malloc((ft_strlen(stash) - i) + 1);
	if (!new)
		return (NULL);
	while (stash[i])
	{
		new[j] = stash[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char 		*chosen_one;

	stash = read_as_buffer(fd, stash);
	chosen_one = next_lining(stash);

	stash = clean_stash(stash);
	
	return (chosen_one);
}

#include <stdio.h>

int main(void)
{
	int return_val;

	return_val = open("test.txt", O_CREAT | O_RDONLY, 0777);
	printf("%s", get_next_line(return_val));
}
