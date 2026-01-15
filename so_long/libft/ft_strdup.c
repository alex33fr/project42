/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:43:16 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/26 11:08:08 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab_dup;
	int		size;

	size = ft_strlen(s);
	tab_dup = ft_calloc(size, sizeof(char));
	if (!tab_dup)
		return (NULL);
	ft_strlcpy(tab_dup, s, size + 1);
	return (tab_dup);
}
