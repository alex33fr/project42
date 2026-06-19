/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 07:45:04 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 15:43:32 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Parse, init, run threads, join, cleanup.
 * @param ac argument count
 * @param av argument vector
 * @return 1 on error, 0 on success
 */
int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;
	int			i;

	memset(&data, 0, sizeof(t_data));
	if (parsing(ac, av, &data))
		return (1);
	if (init_forks(&data) || init_philos(&data))
		return (1);
	i = 0;
	while (i < data.philos)
	{
		pthread_create(&data.threads[i], NULL, philo_loop, &data.philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_routine, &data);
	i = 0;
	while (i < data.philos)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	cleanup(&data);
	return (0);
}
