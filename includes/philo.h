/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:24:50 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/13 18:58:35 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philosophers;
	int				number_of_meal;
	int				time_to_sleep;
	int				*philosophers;
	int				time_to_die;
	int				time_to_eat;
	long			start;
	int				stop;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mstop;
}					t_data;

typedef struct s_philo
{
	pthread_mutex_t		*right_fork;
	pthread_t			*thread;
	int					meal_eaten;
	pthread_mutex_t		*left_fork;
	long				last_meal;
	int					id_philo;
	t_data				*data;
}					t_philo;

void	free_all(t_data *data, t_philo *philo);
int		init_mutex(t_data *data);
int		init_data(int ac, char **av, t_data **data);
int		init_philo(t_data *data, t_philo **philo);
void	ft_usleep(t_data data, int time);
int		is_dead(t_philo *philo);
int		is_number(char	*str);
void	*routine(void *arg);
long	get_time(void);

#endif
