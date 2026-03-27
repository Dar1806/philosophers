/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:43:39 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/27 19:03:01 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mprint);
	if (!arrete(philo) || (msg && !strcmp(msg, "died")))
		printf("%ld %d %s\n", get_time() - philo->data->start,
			philo->id_philo + 1, msg);
	pthread_mutex_unlock(&philo->data->mprint);
}

int	arrete(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->data->mstop);
	stop = philo->data->stop;
	pthread_mutex_unlock(&philo->data->mstop);
	return (stop);
}
