/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:22:00 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/02 23:31:01 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long addr)
{
	char	buffer[32];
	int		i;

	i = 0;
	if (addr == 0)
		return (write(1, "0", 1));
	while (addr)
	{
		buffer[i++] = BASE_HEX[addr % 16];
		addr /= 16;
	}
	while (i--)
		write(1, &buffer[i], 1);
	return (0);
}

int	ft_print_ptr(va_list args)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long)va_arg(args, void *);
	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	ft_puthex_ptr(addr);
	len = 2;
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

