/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/18 16:27:10 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philos **philos, t_argv my_argv, int is_even, pthread_mutex_t *forks)
{
	int	i;

	if (is_even)
		i = 0;
	else
		i = 1;
	while (i < my_argv.num_philos)
	{
		pthread_mutex_lock(forks[philos[i].left]);
		pthread_mutex_lock(forks[philos[i].right]);
		i += 2;
		printf("timestamp_in_ms %d has taken a fork");
	}
	printf("timestamp_in_ms %d is eating");
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
			eat(philos, argv, 1, forks);
		else
			eat(philos, argv, 0, forks);
		i++;
	}
}
