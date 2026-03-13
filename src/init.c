/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:17:38 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/13 18:58:17 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_data(int ac, char **av, t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	(*data)->number_of_philosophers = ft_atoi(av[1]);
	if ((*data)->number_of_philosophers > 200
		|| (*data)->number_of_philosophers < 1)
	{
		free(*data);
		return (0);
	}
	(*data)->start = get_time();
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	(*data)->stop = 0;
	if (ac == 6)
		(*data)->number_of_meal = ft_atoi(av[5]);
	else
		(*data)->number_of_meal = -1;
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->fork)
		return (0);
	pthread_mutex_init(&data->mstop, NULL);
	while (++i < data->number_of_philosophers)
		if (pthread_mutex_init(&(data->fork)[i], NULL))
			return (0);
	return (1);
}

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!*philo)
	{
		free(*philo);
		return (0);
	}
	while (++i < data->number_of_philosophers)
	{
		(*philo)[i].data = data;
		(*philo)[i].meal_eaten = 0;
		(*philo)[i].last_meal = data->start;
		(*philo)[i].id_philo = i;
		(*philo)[i].left_fork = &data->fork[i];
		(*philo)[i].right_fork = &data->fork[(i + 1)
			% data->number_of_philosophers];
		(*philo)[i].thread = malloc(sizeof(pthread_t));
		if (!(*philo)[i].thread)
			return (0);
	}
	return (1);
}
