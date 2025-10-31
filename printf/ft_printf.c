/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:22 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/31 19:52:22 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static int	ft_print(char *tab_p, const char *s, va_list args)
{
	size_t	i;
	char	*str;

	i = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) == 's')
		{
			s += 2;
			str = va_arg(args, char *);
			while (*str)
				tab_p[i++] = *str++;
		}
		else
			tab_p[i++] = *s++;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	n;
	char	*tab_p;
	va_list	args;
	size_t	size;

	size = 5000;
	tab_p = calloc(size, sizeof(char));
	if (!tab_p)
		return (-1);
	va_start(args, s);
	n = ft_print(tab_p, s, args);
	va_end(args);
	write(1, tab_p, n);
	free(tab_p);
    return (n);
}

int main(void){
    int r1,r2;

    r1=printf("1: Hello %s!\n","World");
    r2=ft_printf("2: Hello %s!\n","World");
    printf("result printf=%d | result ft_printf=%d\n\n",r1,r2);

    r1=printf("3: Nombre=%d, Char=%c\n",42,'A');
    r2=ft_printf("4: Nombre=%d, Char=%c\n",42,'A');
    printf("result printf=%d | result ft_printf=%d\n\n",r1,r2);
/*
	r1=printf("5: Hex=%x, Str=%s\n",255,"test");
    r2=ft_printf("6: Hex=%x, Str=%s\n",255,"test");
    printf("result printf=%d | result ft_printf=%d\n",r1,r2);
 */
	return (0);
}

