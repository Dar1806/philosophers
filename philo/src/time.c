/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:00:00 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/26 20:17:32 by nmeunier         ###   ########.fr       */
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

	start = get_time();
	while (!data->stop && (get_time() - start) < time)
		usleep(500);
}
