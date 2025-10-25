/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:55:44 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/20 11:00:02 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
