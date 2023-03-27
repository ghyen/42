/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/27 20:04:22 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex->forks[philo->left]);
		printf_mutex(philo, "has taken a fork");
		pthread_mutex_lock(&philo->mutex->forks[philo->right]);
		printf_mutex(philo, "has taken a fork");
	}
	else
	{
		if (philo->eat_count == 0)
			usleep(1000);
		pthread_mutex_lock(&philo->mutex->forks[philo->right]);
		printf_mutex(philo, "has taken a fork");
		pthread_mutex_lock(&philo->mutex->forks[philo->left]);
		printf_mutex(philo, "has taken a fork");
	}
	printf_mutex(philo, "is eating");
	usleep(philo->env.time_to_eat * 1000);
	pthread_mutex_unlock(&philo->mutex->forks[philo->right]);
	pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
    philo->eat_count++;
}

void	*start_thread(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
    save_now_time(&(philo->env.start_time));
	while (!philo->dead)
	{
		if (philo->env.num_times_must_eat > 1
			&& philo->eat_count == philo->env.num_times_must_eat)
		{
			philo->full = 1;
			break ;
		}
		eat(philo);
		printf_mutex(philo, "is sleeping");
		usleep(philo->env.time_to_sleep * 1000);
		printf_mutex(philo, "is thinking");
	}
    return (NULL);
}

int	monitoring(t_philo **philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < (*philos)->env.num_philos)
		{
			if ((*philos)[i].dead)
			{
				return (4);
			}
		}
	}
}

void	create_philo(t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < (*philos)->env.num_philos)
		pthread_create(&(*philos)[i].pthread, NULL, start_thread, (void *)&(*philos)[i]);
	while (1)
	{
		if (monitoring(philos) == 4)
			break ;
	}
    clean_deadbody(*philos);
}
