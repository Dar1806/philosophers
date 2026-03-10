/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/10 17:19:45 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_struct			*data;
	int					i;

	if (ac != 6 && ac != 5)
		return (0);
	i = 1;
	while (av[++i])
	{
		if (!is_number(av[i]))
			return (0);
	}
	create_struct(ac, av, &data);
	data->start = get_time();

	printf("number_of_philosophers: %d\n", data->number_of_philosophers);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("number_of_meal: %d\n", data->number_of_meal);
	printf("start: %ld\n", data->start);
	return (0);
}
