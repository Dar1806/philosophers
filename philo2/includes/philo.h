/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:24:50 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/23 17:49:02 by nmeunier         ###   ########.fr       */
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
	pthread_mutex_t	mprint;
}					t_data;

typedef struct s_philo
{
	pthread_mutex_t		mlast_meal;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	int					meal_eaten;
	pthread_mutex_t		*left_fork;
	long				last_meal;
	int					id_philo;
	t_data				*data;
}					t_philo;

int		init_data(int ac, char **av, t_data **data);
int		check(t_philo *philo, t_data *data, int i);
int		init_philo(t_data *data, t_philo **philo);
void	print_status(t_philo *philo, char *msg);
void	free_all(t_data *data, t_philo *philo);
void	ft_usleep(t_data *data, long time);
int		init_mutex(t_data *data);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
int		arrete(t_philo *philo);
int		is_number(char	*str);
void	*is_dead(void *arg);
void	*routine(void *arg);
void	stop(t_data *data);
long	get_time(void);

#endif
