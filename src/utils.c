/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:32:32 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/14 23:09:40 by nmeunier         ###   ########.fr       */
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

	i = -1;
	while (++i < data->number_of_philosophers)
		if (philo[i].meal_eaten < data->number_of_meal)
			return (0);
	return (1);
}

int	check(t_philo *philo, t_data *data, int i)
{
	pthread_mutex_lock(&data->mlast_meal);
	if (get_time() - philo[i].last_meal > data->time_to_die)
	{
		pthread_mutex_unlock(&data->mlast_meal);
		printf("%ld %d died\n", get_time()
			- data->start, philo[i].id_philo + 1);
		stop(data);
		return (1);
	}
	if (data->number_of_meal != -1
		&& all_eaten(philo, data))
	{
		pthread_mutex_unlock(&data->mlast_meal);
		stop(data);
		return (1);
	}
	pthread_mutex_unlock(&data->mlast_meal);
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
		usleep(200);
	}
}
