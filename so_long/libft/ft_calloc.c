/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:48:50 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/28 00:40:25 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	t;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	t = size * nmemb;
	tab = malloc(t + 1);
	if (!tab)
		return (NULL);
	ft_bzero(tab, t);
	return (tab);
}
