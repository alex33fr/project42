/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:51:19 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/29 07:24:06 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_counter_key(const char *s, char key)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == key)
			j++;
		i++;
	}
	return (j);
}

static char	*ft_memory_key(const char *s)
{
	size_t i;
	size_t j;
	size_t nbr_key;
	char	*tab_of_types;
	char	key_char;

	i = 0;
	key_char = '%';
	nbr_key = ft_counter_key(s, key_char);
	tab_of_types = ft_calloc(nbr_key + 1, sizeof(char));
	if (!tab_of_types)
		return (NULL);
	while (s[i])
	{
		if (s[i] == key_char)
		{
			tab_of_types[j] = s[i + 1];
			j++;
		}
		i++;
	}
	return (tab_of_types);
}
