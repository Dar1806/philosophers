/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:43:39 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/24 09:47:40 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->mprint);
	if (!philo->data->stop || (msg && !strcmp(msg, "died")))
		printf("%ld %d %s\n", get_time() - philo->data->start,
			philo->id_philo + 1, msg);
	pthread_mutex_unlock(&philo->data->mprint);
}

int	arrete(t_philo *philo)
{
	return (philo->data->stop);
}
