/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:15:23 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/16 13:52:27 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*buf;
	buf = malloc(BUFFER_SIZE + 1);
	read(fd, buf, 5);
	return (buf);
}

#include <stdio.h>

int main(void)
{
	int return_val;

	return_val = open("test.txt", O_CREAT | O_RDONLY, 0777);
	printf("%s", get_next_line(return_val));
}
