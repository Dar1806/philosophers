/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:18:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/19 10:41:24 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	if (data && data->fork)
	{
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->fork[i]);
		free(data->fork);
	}
	if (philo)
		free(philo);
	if (data)
	{
		pthread_mutex_destroy(&data->mstop);
		pthread_mutex_destroy(&data->mlast_meal);
		free(data);
	}
}
a