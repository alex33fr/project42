/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:02:01 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 15:46:54 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Free the three arrays (safe on NULL pointers).
 * @param data shared state
 */
void	free_all(t_data *data)
{
	free(data->forks);
	free(data->philo);
	free(data->threads);
}

/**
 * @brief Destroy every mutex then free the arrays.
 * @param data shared state
 */
void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free_all(data);
}
