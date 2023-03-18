/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/18 20:11:43 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philos **philos, t_env my_env, int is_even, t_mutex *mutex_info)
{
	int	i;

	if (is_even)
		i = 0;
	else
		i = 1;
	while (i < my_env.num_philos)
	{
		pthread_mutex_lock(forks[philos[i].left]);
		pthread_mutex_lock(forks[philos[i].right]);
		i += 2;
		printf("%d has taken a fork", );
	}
	printf("time id is eating", );
	//lock
	//eat
	//unlock
}

void	philo_start(t_philos **philos, t_env my_env, t_mutex *mutex_info)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_create(philos[i].pthread, NULL, eat, (philos, my_env, i
				% 2 == 0, mutex_info));
		i++;
	}
}
