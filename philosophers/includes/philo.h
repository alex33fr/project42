/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:14:09 by aprivalo          #+#    #+#             */
/*   Updated: 2026/06/19 15:51:15 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	long			philos;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			limiter_eat;
	long			start_time;
	int				dead;
	int				all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	struct s_philo	*philo;
	pthread_t		*threads;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

long	get_time_us(void);
void	ft_usleep(long ms);
void	print_status(t_philo *philo, char *msg);

int		parsing(int ac, char **av, t_data *data);
int		ft_atoi_philo(char *s, long *res);

int		init_forks(t_data *data);
int		init_philos(t_data *data);

void	free_all(t_data *data);
void	cleanup(t_data *data);

void	*philo_loop(void *arg);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);

int		take_forks(t_philo *philo);
void	release_forks(t_philo *philo);

void	*monitor_routine(void *arg);
int		check_death(t_data *data);
int		check_all_ate(t_data *data);

#endif
