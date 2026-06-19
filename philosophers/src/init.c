/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:49:40 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 22:16:04 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Allocate forks and init all mutexes.
 * @param data shared state
 * @return 1 on error, 0 on success
 */
int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			free_all(data);
			printf("[Error 4]: pthread_mutex_init is broken in forks!");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->death_mutex, NULL))
	{
		free_all(data);
		return (1);
	}
	return (0);
}

/**
 * @brief Fill one philosopher's fields and fork pointers.
 * @param data shared state
 * @param i index of the philosopher
 */
static void	set_philo(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo[i].meals_eaten = 0;
	data->philo[i].last_meal = data->start_time;
	data->philo[i].data = data;
	data->philo[i].left_fork = &data->forks[i];
	data->philo[i].right_fork = &data->forks[(i + 1) % data->philos];
}

/**
 * @brief Allocate philos/threads and init their mutexes.
 * @param data shared state
 * @return 1 on error, 0 on success
 */
int	init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->philos);
	data->threads = malloc(sizeof(pthread_t) * data->philos);
	if (!data->philo || !data->threads)
	{
		free_all(data);
		return (1);
	}
	data->start_time = get_time_us();
	data->dead = 0;
	data->all_ate = 0;
	i = 0;
	while (i < data->philos)
	{
		set_philo(data, i);
		if (pthread_mutex_init(&data->philo[i].meal_mutex, NULL))
		{
			free_all(data);
			printf("[Error 5]: pthread_mutex_init is broken in philos!");
			return (1);
		}
		i++;
	}
	return (0);
}
