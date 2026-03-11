/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/03/11 16:53:01 by nmeunier         ###   ########.fr       */
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
	
	return (0);
}
