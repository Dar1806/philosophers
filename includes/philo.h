/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:24:50 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/11 16:46:35 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_struct {
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_meal;
	long	start;
	int		*philosophers;
	int		stop;
}					t_struct;

void	create_struct(int ac, char **av, t_struct **data);
int		is_number(char	*str);
long	get_time(void);

#endif
