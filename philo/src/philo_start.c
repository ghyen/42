/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/19 19:00:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo	*philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(forks[philo.left]);
		printf_mutex(philo, "has taken a fork");
		pthread_mutex_lock(forks[philo.right]);
		printf_mutex(philo, "has taken a fork");
	}
	else
	{
		if (philo->env.eat_count == 0)
			usleep(1000);
		pthread_mutex_lock(forks[philo.right]);
		printf_mutex(philo, "has taken a fork");
		pthread_mutex_lock(forks[philo.left]);
		printf_mutex(philo, "has taken a fork");
	}
	printf_mutex(philo, "is eating");
	usleep(philo->env.time_to_eat);
	pthread_mutex_unlock(forks[philo.right]);
	pthread_mutex_unlock(forks[philo.left]);
}

void	start_thread(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	save_now_time(&philo->env.start_time);
	while (!philo->dead && !philo->full)
	{
		eat(philo);
		printf_mutex(philo, "is sleeping");
		usleep(philo->env.time_to_sleep);
		printf_mutex(philo, "is thinking");
	}
}

int	monitoring(t_philo **philos)
{
	while(checkdead)
	{
		
	}
}
void	create_philo(t_philos **philos, t_mutex *mutex_info)
{
	int	i;

	i = -1;
	while (++i < (*philos)->env.num_philos)
		pthread_create((*philos)[i].pthread, NULL, start_thread, (*philos)[i]);
	while (1)
	{
		if (monitoring(philos) == 4)
			break;
	}
}
