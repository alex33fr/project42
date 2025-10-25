/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:49:40 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/20 10:52:16 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cb;

	cb = (char *)big;
	i = 0;
	if (*little == '\0')
		return (cb);
	while (cb[i] && i < len)
	{
		j = 0;
		while (cb[i + j] && little[j] && i + j < len && cb[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (&cb[i]);
		i++;
	}
	return (NULL);
}
