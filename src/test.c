/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:06:32 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/10 16:02:25 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

typedef struct s_struct {
	int				incr;
	int				max;
	int				n_thread;
	int				turn;
	pthread_mutex_t	m_incr;
}					t_struct;

typedef struct s_targ {
	int			id;
	t_struct	*data;
}				t_targ;

void	*job(void *arg)
{
	t_struct	*data;
	t_targ		*targ;
	int			id;

	targ = (t_targ *)arg;
	data = targ->data;
	id = targ->id;
	while (1)
	{
		pthread_mutex_lock(&data->m_incr);
		if (data->incr >= data->max)
		{
			pthread_mutex_unlock(&data->m_incr);
			break ;
		}
		if (data->turn % data->n_thread == id)
		{
			data->incr++;
			printf("thread %d = %d\n", id + 1, data->incr);
			data->turn++;
		}
		pthread_mutex_unlock(&data->m_incr);
		usleep(100);
	}
	return NULL;
}

int	main(int ac, char **av)
{
	pthread_t	*thread;
	int			nbr_thread;
	int			i;
	int			max;
	t_struct	*data;
	t_targ		*targ;

	if (ac != 3)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	i = -1;
	nbr_thread = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	thread = malloc(sizeof(pthread_t) * nbr_thread);
	data = malloc(sizeof(t_struct) * nbr_thread);
	targ = malloc(sizeof(t_targ) * nbr_thread);
	pthread_mutex_init(&data->m_incr, NULL);
	data->max = max;
	data->n_thread = nbr_thread;
	data->incr = 0;
	data->turn = 0;
	while (++i < nbr_thread)
	{
		targ[i].id = i;
		targ[i].data = data;
		pthread_create(&thread[i], NULL, job, &targ[i]);
	}
	i = -1;
	while (++i < nbr_thread)
		pthread_join(thread[i], NULL);
}
