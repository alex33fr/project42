/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:53:28 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/15 10:53:54 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;
	size_t i;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
