/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:46:32 by aprivalo          #+#    #+#             */
/*   Updated: 2025/10/20 10:47:46 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab_dup;
	int		size;

	size = ft_strlen(s);
	tab_dup = malloc(sizeof(char) * (size + 1));
	if (!tab_dup)
		return (NULL);
	ft_strlcpy(tab_dup, s, size + 1);
	return (tab_dup);
}
