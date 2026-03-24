/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:43:39 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/23 22:36:58 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *msg)
{
	int	stopped;

	pthread_mutex_lock(&philo->data->mstop);
	stopped = philo->data->stop;
	pthread_mutex_unlock(&philo->data->mstop);
	pthread_mutex_lock(&philo->data->mprint);
	if (!stopped || (msg && !strcmp(msg, "died")))
		printf("%ld %d %s\n", get_time() - philo->data->start,
			philo->id_philo + 1, msg);
	pthread_mutex_unlock(&philo->data->mprint);
}
