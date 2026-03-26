/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:32:32 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/26 20:27:33 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_number(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	stop(t_data *data)
{
	pthread_mutex_lock(&data->mstop);
	data->stop = 1;
	pthread_mutex_unlock(&data->mstop);
}

int	all_eaten(t_philo *philo, t_data *data)
{
	int	i;
	int	meals;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&philo[i].mlast_meal);
		meals = philo[i].meal_eaten;
		pthread_mutex_unlock(&philo[i].mlast_meal);
		if (meals < data->number_of_meal)
			return (0);
	}
	return (1);
}

int	check(t_philo *philo, t_data *data, int i)
{
	long	last;
	int		dead;
	int		full;

	pthread_mutex_lock(&philo[i].mlast_meal);
	last = philo[i].last_meal;
	pthread_mutex_unlock(&philo[i].mlast_meal);
	dead = (get_time() - last >= data->time_to_die);
	full = (data->number_of_meal != -1 && all_eaten(philo, data));
	if (dead)
	{
		stop(data);
		print_status(&philo[i], "died");
		return (1);
	}
	if (full)
	{
		stop(data);
		return (1);
	}
	return (0);
}

void	*is_dead(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo[0].data;
	while (1)
	{
		i = -1;
		while (++i < philo->data->number_of_philosophers)
			if (check(philo, data, i))
				return (NULL);
		usleep(500);
	}
}
