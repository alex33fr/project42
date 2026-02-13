/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_ber_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/02/13 16:13:17 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_has_ber_extension(char *file)
{
	int	i;

	if (!file)
		return (0);
	i = ft_strlen(file);
	if (i < 4)
		return (0);
	if (file[i - 4] != '.'
		|| file[i - 3] != 'b'
		|| file[i - 2] != 'e'
		|| file[i - 1] != 'r')
		return (0);
	return (1);
}
