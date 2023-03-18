/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/18 15:39:40 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philos **philos, char **argv, int is_even)
{
	int	i;

	if (is_even)
		i = 0;
	else
		i = 1;
	while (i <)
	{
	}
	//lock
	//eat
	//unlock
}

void	philo_start(t_philos **philos, t_argv my_argv, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i % 2 == 0)
		{
			eat(philos, argv, 1);
		}
		else
			eat(philos, argv, 0);
		i++;
	}
}
