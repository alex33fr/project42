/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:48:50 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/23 15:28:20 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	t;

	t = size * nmemb;
	if (nmemb && size && t < nmemb)
		return (NULL);
	tab = malloc(t);
	if (!tab)
		return (NULL);
	ft_bzero(tab, t);
	return (tab);
}
