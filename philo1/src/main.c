/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/14 22:52:11 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start(t_data *data, t_philo *philo, pthread_t *monitor)
{
	int	i;

	i = -1;
	if (pthread_create(monitor, NULL, is_dead, philo))
		return (0);
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*data;
	t_philo			*philo;
	pthread_t		monitor;
	int				i;

	if (ac != 6 && ac != 5)
		return (0);
	i = 0;
	while (av[++i])
		if (!is_number(av[i]))
			return (0);
	if (!init_data(ac, av, &data) || !init_mutex(data)
		|| !init_philo(data, &philo))
		return (0);
	if (!start(data, philo, &monitor))
		return (0);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	free_all(data, philo);
	return (0);
}
