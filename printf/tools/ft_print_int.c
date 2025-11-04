/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:32:55 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/04 11:25:04 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args)
{
	int		asc;
	int		len;
	char	*str;

	asc = va_arg(args, int);
	str = ft_itoa(asc);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
