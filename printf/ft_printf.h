/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:15:33 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/04 11:13:59 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_print_char(va_list args);
int	ft_print_string(va_list args);
int	ft_print_int(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_dec(va_list args);
int	ft_print_hex_lo(va_list args);
int	ft_print_hex_up(va_list args);
int	ft_print_percent(va_list args);

#endif
