/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:52:41 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/20 10:54:44 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*p;
	char	*result;

	cc = (char)c;
	p = (char *)s;
	result = NULL;
	while (*p)
	{
		if (*p == cc)
			result = p;
		p++;
	}
	if (cc == '\0')
		return (p);
	return (result);
}
