/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:30:04 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/02 18:21:35 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(va_list args)
{
	char	*str;
	int	len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	if (!str)
		str = "(null)";
	write(1, str, len);
	return (len);
}
