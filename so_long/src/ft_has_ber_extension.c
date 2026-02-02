/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_ber_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:45:46 by aprivalo          #+#    #+#             */
/*   Updated: 2026/01/26 17:41:09 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_has_ber_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'b'
		|| filename[len - 2] != 'e'
		|| filename[len - 1] != 'r')
		return (0);
	return (1);
}
