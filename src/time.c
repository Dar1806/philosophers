/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:00:00 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/19 08:55:36 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	tv;
	int				error;

	error = gettimeofday(&tv, NULL);
	if (error)
		return (0);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	ft_usleep(t_data *data, int time)
{
	long	max;

	max = get_time() + time;
	while (get_time() < max)
	{
		pthread_mutex_lock(&data->mstop);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->mstop);
			break ;
		}
		pthread_mutex_unlock(&data->mstop);
		if (usleep(200) == -1)
			break ;
	}
}
