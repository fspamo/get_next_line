/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbozkurt <cbozkurt@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:39:15 by cbozkurt          #+#    #+#             */
/*   Updated: 2026/02/19 12:19:43 by cbozkurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strchr(const char *s, int ch)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((unsigned char)s[i] == (unsigned char)ch)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_length;
	int		i;

	i = 0;
	str_length = ft_strlen(s);
	str = malloc(str_length + 1);
	if (!str)
		return (NULL);
	while (i < str_length)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	// if (!s2)
	// 	return (NULL);
	// if (!s1)
	// 	return (ft_strdup(s2));
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + s2_len] = '\0';
	return (str);
}

