/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 09:11:13 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 11:28:57 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Current time in microseconds.
 * @return the timestamp in us
 */
long	get_time_us(void)
{
	struct timeval	t;
	long			us;

	gettimeofday(&t, NULL);
	us = t.tv_sec * 1000000L + t.tv_usec;
	return (us);
}

/**
 * @brief Precise sleep of ms milliseconds (microsecond resolution).
 * @param ms duration in milliseconds
 */
void	ft_usleep(long ms)
{
	long	start;
	long	now;
	long	us;

	us = ms * 1000;
	start = get_time_us();
	now = start;
	while (now - start < us)
	{
		usleep(200);
		now = get_time_us();
	}
}

/**
 * @brief Print a status line if the sim is still running.
 * @param philo the philosopher
 * @param msg the status text
 */
void	print_status(t_philo *philo, char *msg)
{
	t_data	*data;
	long	timestamp;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->death_mutex);
	if (!data->dead && !data->all_ate)
	{
		timestamp = (get_time_us() - data->start_time) / 1000;
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&data->death_mutex);
	pthread_mutex_unlock(&data->print_mutex);
}
