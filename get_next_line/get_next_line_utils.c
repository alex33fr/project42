/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:11:44 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/07 16:39:31 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	t;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	t = size * nmemb;
	tab = malloc(t);
	if (!tab)
		return (NULL);
	ft_bzero(tab, t);
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab_join;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tab_join = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!tab_join)
		return (NULL);
	ft_strlcpy(tab_join, s1, len_s1 + 1);
	ft_strlcpy(tab_join + len_s1, s2, len_s2 + 1);
	free(s1);
	return (tab_join);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*tab_dup;
	int		size;

	size = ft_strlen(s);
	tab_dup = malloc(sizeof(char) * (size + 1));
	if (!tab_dup)
		return (NULL);
	ft_strlcpy(tab_dup, s, size + 1);
	return (tab_dup);
}
