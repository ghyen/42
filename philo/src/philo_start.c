/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/30 01:20:22 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->eat_count == 0)
		usleep(1000 * philo->env.time_to_eat);
    pthread_mutex_lock(&philo->mutex->forks[philo->left]);
	printf_mutex(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->forks[philo->right]);
	printf_mutex(philo, "has taken a fork");
	printf_mutex(philo, "is eating");
	usleep(philo->env.time_to_eat * 1000);
	save_now_time(&(philo->env.last_eat_time));
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex->forks[philo->right]);
	pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
}

void	*start_thread(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	save_now_time(&(philo->env.start_time));
	while (!check_dead(philo))
	{
		if (philo->env.num_times_must_eat > 0
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

bool	monitoring(t_philo **philos)
{
	int	num_philo;
	int	i;

	i = -1;
	num_philo = philos[0]->env.num_philos;
	while (++i < num_philo)
		if (check_dead(philos[i]))
			return (0);
	return (1);
}

void	create_philo(t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < (*philos)->env.num_philos)
    {
        write(1,"is created\n", 11);
        pthread_create(&(*philos)[i].pthread, NULL, start_thread,
				(void *)&(*philos)[i]);
    }
	while (monitoring(philos))
		;
	clean_deadbody(*philos);
}
