/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:17:38 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/12 18:14:59 by nmeunier         ###   ########.fr       */
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
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->number_of_meal = ft_atoi(av[5]);
	else
		(*data)->number_of_meal = -1;
	return (1);
}

int	init_mutex(t_data *data, pthread_mutex_t **mutex)
{
	int	i;

	i = -1;
	*mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!*mutex)
	{
		free(*mutex);
		return (0);
	}
	while (++i < data->number_of_philosophers)
		if (pthread_mutex_init(&(*mutex)[i], NULL))
			return (0);
	data->fork = *mutex;
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
		(*philo)[i].meal_eaten = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].id_philo = i;
		(*philo)[i].left_fork = &data->fork[i];
		(*philo)[i].right_fork = &data->fork[(i + 1)
			% data->number_of_philosophers];
		(*philo)[i].data = data;
	}
	return (1);
}
