/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:18:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/12 18:05:21 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_data *data, pthread_mutex_t *mutex, t_philo *philo)
{
	int	i;

	i = -1;
	if (mutex && data)
	{
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&mutex[i]);
		free(mutex);
	}
	if (data)
		free(data);
	if (philo)
		free(philo);
}
