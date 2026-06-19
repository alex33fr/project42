/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:53:55 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 11:39:31 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Stop check (dead or all_ate) read under death_mutex.
 * @param data shared state
 * @return 1 if the sim must stop, 0 otherwise
 */
static int	sim_over(t_data *data)
{
	int	over;

	pthread_mutex_lock(&data->death_mutex);
	over = (data->dead || data->all_ate);
	pthread_mutex_unlock(&data->death_mutex);
	return (over);
}

/**
 * @brief Update meal info under meal_mutex, print, wait time_eat.
 * @param philo the philosopher
 * @return 1 if the sim ended, 0 otherwise
 */
int	philo_eat(t_philo *philo)
{
	int	over;

	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_us();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_eat);
	over = sim_over(philo->data);
	return (over);
}

/**
 * @brief Print "is sleeping" and wait time_sleep.
 * @param philo the philosopher
 * @return 1 if the sim ended, 0 otherwise
 */
int	philo_sleep(t_philo *philo)
{
	int	over;

	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_sleep);
	over = sim_over(philo->data);
	return (over);
}

/**
 * @brief Print "is thinking" and wait to free forks for neighbours.
 * @param philo the philosopher
 * @return 1 if the sim ended, 0 otherwise
 */
int	philo_think(t_philo *philo)
{
	int		over;
	long	t;

	print_status(philo, "is thinking");
	t = philo->data->time_die - philo->data->time_eat - philo->data->time_sleep;
	if (t < 0)
		t = 0;
	ft_usleep(t / 2);
	over = sim_over(philo->data);
	return (over);
}

/**
 * @brief Philosopher thread: loop think, take forks, eat, drop, sleep.
 * @param arg the philosopher (t_philo *)
 * @return NULL
 */
void	*philo_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 2);
	while (1)
	{
		if (sim_over(philo->data))
			break ;
		if (philo_think(philo))
			break ;
		if (take_forks(philo))
			break ;
		if (philo_eat(philo))
		{
			release_forks(philo);
			break ;
		}
		release_forks(philo);
		if (philo_sleep(philo))
			break ;
	}
	return (NULL);
}
