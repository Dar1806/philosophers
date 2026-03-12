/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/12 19:09:26 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data				*data;
	pthread_mutex_t		*mutex;
	t_philo				*philo;
	int					i;

	if (ac != 6 && ac != 5)
		return (0);
	i = 0;
	while (av[++i])
		if (!is_number(av[i]))
			return (0);
	if (!init_data(ac, av, &data))
		return (0);
	if (!init_mutex(data, &mutex) || !init_philo(data, &philo))
		return (0);
	free_all(data, mutex, philo);
	return (0);
}
