/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 23:19:20 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 23:09:51 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Parse a positive int (rejects junk and overflow).
 * @param s the string to convert
 * @param res where the value is stored
 * @return 1 on invalid input, 0 on success
 */
int	ft_atoi_philo(char *s, long *res)
{
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10 + (s[i] - '0');
			if (nb > 2147483647)
				return (1);
		}
		else
			return (1);
		i++;
	}
	*res = nb;
	return (0);
}

/**
 * @brief Convert the 4 (or 5) numeric args into data (no short-circuit).
 * @param ac argument count
 * @param av argument vector
 * @param data data to fill
 * @return 1 if any arg is invalid, 0 if all are valid
 */
static int	fill_args(int ac, char **av, t_data *data)
{
	int	err;

	data->limiter_eat = -1;
	err = ft_atoi_philo(av[1], &data->philos);
	err += ft_atoi_philo(av[2], &data->time_die);
	err += ft_atoi_philo(av[3], &data->time_eat);
	err += ft_atoi_philo(av[4], &data->time_sleep);
	if (ac == 6)
		err += ft_atoi_philo(av[5], &data->limiter_eat);
	return (err != 0);
}

/**
 * @brief Validate argv and fill data.
 * @param ac argument count
 * @param av argument vector
 * @param data data to fill
 * @return 1 on invalid input, 0 on success
 */
int	parsing(int ac, char **av, t_data *data)
{
	int	err;

	if (ac != 5 && ac != 6)
	{
		printf("[Error 1] usage: ./philo n die eat sleep [must_eat]\n");
		return (1);
	}
	err = fill_args(ac, av, data);
	if (err)
	{
		printf("[Error 2] Bads args, RTFM! BTFM! PTFM!\n");
		return (1);
	}
	if (data->philos < 1 || data->time_die < 1
		|| data->time_eat < 1 || data->time_sleep < 1)
	{
		printf("[Error 3] Cannot be under < 1, RTFM! BTFM! PTFM!\n");
		return (1);
	}
	return (0);
}
