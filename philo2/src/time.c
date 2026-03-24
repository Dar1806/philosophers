/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:00:00 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/23 22:33:45 by nmeunier         ###   ########.fr       */
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

void	ft_usleep(t_data *data, long time)
{
	long	start;
	int		stopped;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&data->mstop);
		stopped = data->stop;
		pthread_mutex_unlock(&data->mstop);
		if (stopped || (get_time() - start) >= time)
			break ;
		usleep(50);
	}
}
