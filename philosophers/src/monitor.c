/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:04:39 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 11:33:28 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Set dead under death_mutex, then print "died".
 * @param data shared state
 * @param id id of the dead philosopher
 */
static void	announce_death(t_data *data, int id)
{
	pthread_mutex_lock(&data->death_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", (get_time_us() - data->start_time) / 1000, id);
	pthread_mutex_unlock(&data->print_mutex);
}

/**
 * @brief Kill any philo past time_die since its last meal.
 * @param data shared state
 * @return 1 if someone died, 0 otherwise
 */
int	check_death(t_data *data)
{
	int		i;
	long	last;

	i = 0;
	while (i < data->philos)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		last = data->philo[i].last_meal;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		if (get_time_us() - last >= data->time_die * 1000)
		{
			announce_death(data, data->philo[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Stop once every philo reached the meal limit.
 * @param data shared state
 * @return 1 if the sim should stop, 0 otherwise
 */
int	check_all_ate(t_data *data)
{
	int	i;
	int	full;

	if (data->limiter_eat < 0)
		return (0);
	i = 0;
	full = 0;
	while (i < data->philos)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		if (data->philo[i].meals_eaten >= data->limiter_eat)
			full++;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		i++;
	}
	if (full < data->philos)
		return (0);
	pthread_mutex_lock(&data->death_mutex);
	data->all_ate = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}

/**
 * @brief Monitor thread: poll death and meal limit every ~1ms.
 * @param arg the shared data (t_data *)
 * @return NULL
 */
void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		stop;

	data = (t_data *)arg;
	stop = 0;
	while (stop == 0)
	{
		if (check_death(data) || check_all_ate(data))
			stop = 1;
		else
			ft_usleep(1);
	}
	return (NULL);
}
