/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:22 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/02 18:35:23 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_type_args(char type, va_list args)
{
	int	len;

	if (type == 'c')
		len = ft_print_char(args);
	else if (type == 's')
		len = ft_print_string(args);
	else if (type == 'd' || type == 'i')
		len = ft_print_int (args);
	return (len);
}

static int	ft_define_format(const char *s, va_list args)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			i += ft_type_args(*(s + 1), args);
			s += 2;
		}
		else
		{
			write(1, s, 1);
			i++;
			s++;
		}
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	len;
	va_list	args;

	if (!s)
		return (0);
	va_start(args, s);
	len = ft_define_format(s, args);
	va_end(args);
    return (len);
}
