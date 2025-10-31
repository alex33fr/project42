/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:22 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/31 07:00:30 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_vsnprintf(char *tab_p, size_t size, const char *s, va_list ap)
{
	size_t	i;
	char	*str;

	i = 0;
	while (*s && i + 1 < size)
	{
		if (*s == '%' && *(s + 1) == 's')
		{
			s += 2;
			str = va_arg(ap, char *);
			while (*str && i + 1 < size)
				tab_p[i++] = *str++;
		}
		else
			tab_p[i++] = *s++;
	}
	tab_p[i] = '\0';
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int n;
	size_t size;
	char *tab_p;
	va_list ap;

	size = 1024;
	tab_p = ft_calloc(size, sizeof(char));
	if (!tab_p)
		return (0);
	va_start(ap, s);
	n = ft_vsnprintf(tab_p, size, s, ap);
	va_end(ap);
	write(1, tab_p, n);
	free(tab_p);
	return (n);
}
