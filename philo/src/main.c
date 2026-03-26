/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/26 20:10:39 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start(t_data *data, t_philo *philo, pthread_t *monitor)
{
	int	i;

	i = -1;
	data->start = get_time();
	while (++i < data->number_of_philosophers)
	{
		philo[i].last_meal = data->start;
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
	}
	if (pthread_create(monitor, NULL, is_dead, philo))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*data;
	t_philo			*philo;
	pthread_t		monitor;
	int				i;

	data = NULL;
	philo = NULL;
	if (ac != 6 && ac != 5)
		return (0);
	i = 0;
	while (av[++i])
		if (!is_number(av[i]))
			return (0);
	if (!init_data(ac, av, &data) || !init_mutex(data)
		|| !init_philo(data, &philo) || !start(data, philo, &monitor))
	{
		free_all(data, philo);
		return (0);
	}
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	pthread_join(monitor, NULL);
	free_all(data, philo);
	return (0);
}
