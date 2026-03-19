/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:40:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/19 10:02:20 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	arrete(t_philo	*philo)
{
	int	stopped;

	pthread_mutex_lock(&philo->data->mstop);
	stopped = (philo->data->stop == 1);
	pthread_mutex_unlock(&philo->data->mstop);
	return (stopped);
}

void	eating(t_philo *philo)
{
	if (arrete(philo))
		return ;
	pthread_mutex_lock(philo->left_fork);
	if (arrete(philo))
		return (pthread_mutex_unlock(philo->left_fork), (void)0);
	pthread_mutex_lock(philo->right_fork);
	if (arrete(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), (void)0);
	}
	pthread_mutex_lock(&philo->data->mlast_meal);
	philo->last_meal = get_time();
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->data->mlast_meal);
	printf("%ld %d has taken a fork\n", get_time() - philo->data->start,
		philo->id_philo + 1);
	printf("%ld %d has taken a fork\n", get_time() - philo->data->start,
		philo->id_philo + 1);
	printf("%ld %d is eating\n", get_time() - philo->data->start,
		philo->id_philo + 1);
	ft_usleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	if (arrete(philo))
		return ;
	printf("%ld %d is sleeping\n", get_time() - philo->data->start,
		philo->id_philo + 1);
	ft_usleep(philo->data, philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (arrete(philo))
		return ;
	printf("%ld %d is thinking\n", get_time() - philo->data->start,
		philo->id_philo + 1); 
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->mlast_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->mlast_meal);
	if (philo->data->number_of_philosophers == 1)
	{
		printf("%ld 1 has taken a fork\n", get_time() - philo->data->start);
		ft_usleep(philo->data, philo->data->time_to_die + 1);
		return (NULL);
	}
	if (philo->id_philo % 2 == 1)
		ft_usleep(philo->data, philo->data->time_to_eat / 2);
	while (!arrete(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
