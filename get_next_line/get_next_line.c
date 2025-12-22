/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:11:30 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/20 23:39:38 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*read_to_rest(int fd, char *rest)
{
	char	*buf;
	ssize_t	rd;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd > 0 && (!rest || !ft_strchr(rest, '\n')))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		if (rd > 0)
		{
			buf[rd] = '\0';
			rest = ft_strjoin(rest, buf);
		}
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_to_rest(fd, rest);
	if (!tmp)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = tmp;
	if (!*rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_ret_line(rest);
	rest = ft_upd_rest(rest);
	return (line);
}

/*
char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buf;
	ssize_t		tab_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	tab_read = 0;
	while (!rest || !ft_strchr(rest, '\n'))
	{
		tab_read = read(fd, buf, BUFFER_SIZE);
		if (tab_read <= 0)
			break ;
		buf[tab_read] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	free(buf);
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
*/
