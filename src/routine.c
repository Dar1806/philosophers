/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:40:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/13 18:54:00 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_t	*mutex;
	t_data			*data;
	int				i;

	data = philo->data;
	mutex = data->fork;
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&mutex[i]);
		if (get_time() - philo[i].last_meal > data->time_to_die)
		{
			pthread_mutex_unlock(&mutex[i]);
			pthread_mutex_lock(&mutex[philo[i].id_philo]);
			printf("%ld %d died\n", get_time()
				- data->start, philo[i].id_philo + 1);
			data->stop = 1;
			pthread_mutex_unlock(&mutex[philo[i].id_philo]);
			return (0);
		}
		pthread_mutex_unlock(&mutex[i]);
	}
	return (1);
}

int	arrete(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->mstop);
	if (philo->data->stop == 1)
	{
		pthread_mutex_lock(&philo->data->mstop);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mstop);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (arrete(philo) == 0)
	{
		is_dead(philo);
		usleep(200);
	}
	return (NULL);
}
