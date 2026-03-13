/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:18:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/13 19:00:01 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	if (data->fork && data)
	{
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->fork[i]);
		free(data->fork);
	}
	if (data)
		free(data);
	if (philo)
		free(philo);
	i = -1;
	while (i < data->number_of_philosophers)
	{
		philo[i].thread = NULL;
		i++;
	}
}
