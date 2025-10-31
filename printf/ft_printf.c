/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:22 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/31 17:03:05 by aprivalo         ###   ########.fr       */
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

static int	ft_vsnprintf(char *tab_p, size_t size, const char *s, va_list args)
{
	size_t	i;

	i = 0;
	while (*s && i + 1 < size)
	{
		if (*s == '%' && *(s + 1) == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else
		tab_p[i++] = *s++;
	}
	tab_p[i] = '\0';
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	n;
	size_t	size;
	char	*tab_p;
	va_list	ap;

	size = 1024;
	tab_p = malloc(size);
	if (!tab_p)
		return (-1);
		va_start(ap, s);
	n = ft_vsnprintf(tab_p, size, s, ap);
	va_end(ap);
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

