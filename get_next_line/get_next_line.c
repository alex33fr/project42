/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:11:30 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/07 16:39:56 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*p;

	cc = (char)c;
	p = (char *)s;
	while (*p)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	if (cc == '\0')
		return (p);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

static	char	*ft_ret_line(char *s)
{
	ssize_t	i;
	char	*str;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str[i] = s[i];
			i++;
			break ;
		}
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_upd_rest(char *rest)
{
	ssize_t	i;
	char	*upd_rest;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			if (rest[i + 1])
				upd_rest = ft_strdup(rest + i + 1);
			else
				upd_rest = NULL;
			free(rest);
			return (upd_rest);
		}
		i++;
	}
	free(rest);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		tab_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab_read = 1;
	while ((!rest || !ft_strchr(rest, '\n')) && tab_read > 0)
	{
		tab_read = read(fd, buf, BUFFER_SIZE);
		if (tab_read <= 0)
			break ;
		buf[tab_read] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	if (tab_read == -1 || !rest || !*rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_ret_line(rest);
	rest = ft_upd_rest(rest);
	return (line);
}
