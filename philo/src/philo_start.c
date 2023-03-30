/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/03/30 22:55:33 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0 && philo->eat_count == 0)
		usleep(1000);
    pthread_mutex_lock(&philo->mutex->forks[philo->left]);
	printf_mutex(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->forks[philo->right]);
	printf_mutex(philo, "has taken a fork");
	printf_mutex(philo, "is eating");
	usleep(philo->env->time_to_eat * 1000);
	save_now_time(&(philo->last_eat_time));
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex->forks[philo->right]);
	pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
}

void	*start_thread(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	write(1,"is created\n", 11);
	save_now_time(&(philo->last_eat_time));
	while (!check_dead(philo))
	{
		if (philo->env->num_times_must_eat > 0
			&& philo->eat_count == philo->env->num_times_must_eat)
		{
			pthread_mutex_lock(&philo->mutex->full[philo->id]);
			philo->full = 1;
			pthread_mutex_unlock(&philo->mutex->full[philo->id]);
			break ;
		}
		eat(philo);
		printf_mutex(philo, "is sleeping");
		usleep(philo->env->time_to_sleep * 1000);
		printf_mutex(philo, "is thinking");
	}
	return (NULL);
}

int	is_all_full(t_philo **philos)
{
	int	i;
	int	is_full;

	is_full = 0;
	i = -1;
	while (++i < (*philos)->env->num_philos)
	{
		pthread_mutex_lock(&(*philos)->mutex->full[i]);
		if ((*philos)[i].full == 0)
			is_full = 1;
		pthread_mutex_unlock(&(*philos)->mutex->full[i]);
		if (is_full)
			break ;
	}
	if (i == (*philos)->env->num_philos)
		return (1);
	return (0);
}

int	monitoring(t_philo **philos)
{
	if (check_dead(philos[0]))
		return (0);
	if (is_all_full(philos))
		return (0);
	return (1);
}

void	create_philo(t_philo **philos)
{
	int	i;

	save_now_time(&philos[0]->env->start_time);
	i = -1;
	while (++i < (*philos)->env->num_philos)
    {
        pthread_create(&(*philos)[i].pthread, NULL, start_thread,
				(void *)&(*philos)[i]);
    }
	while (monitoring(philos))
		;
	clean_deadbody(philos);
}
