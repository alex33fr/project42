/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:48:41 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/20 11:01:37 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while ((p1[i] || p2[i]) && i < n)
	{
		if (p1[i] < p2[i])
			return (p1[i] - p2[i]);
		else if (p1[i] > p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
