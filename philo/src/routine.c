/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:40:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/27 19:54:49 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
}

void	eating(t_philo *philo)
{
	if (arrete(philo))
		return ;
	take_forks(philo);
	pthread_mutex_lock(&philo->mlast_meal);
	philo->last_meal = get_time();
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->mlast_meal);
	print_status(philo, "is eating");
	ft_usleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	if (arrete(philo))
		return ;
	print_status(philo, "is sleeping");
	ft_usleep(philo->data, philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	long	think;

	if (arrete(philo))
		return ;
	print_status(philo, "is thinking");
	if (philo->data->number_of_philosophers % 2 != 0)
	{
		think = philo->data->time_to_eat * 2 - philo->data->time_to_sleep;
		if (think > 0)
			ft_usleep(philo->data, think);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philosophers == 1)
	{
		print_status(philo, "has taken a fork");
		usleep(philo->data->time_to_die * 990);
		stop(philo->data);
		return (NULL);
	}
	if (philo->id_philo % 2 != 0
		|| (philo->data->number_of_philosophers % 2 != 0
			&& philo->id_philo == philo->data->number_of_philosophers - 1))
		ft_usleep(philo->data, philo->data->time_to_eat);
	while (!arrete(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
