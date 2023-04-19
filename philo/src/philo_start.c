/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:11:22 by edwin             #+#    #+#             */
/*   Updated: 2023/04/07 18:50:14 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2 == 1 && philo->eat_count == 0)
		usleep(200);
	if (!check_dead(philo))
	{
		pthread_mutex_lock(&philo->mutex->forks[philo->left]);
		printf_mutex(philo, "has taken a fork");
		pthread_mutex_lock(&philo->mutex->forks[philo->right]);
		printf_mutex(philo, "has taken a fork");
		philo->eat_count++;
		printf_mutex(philo, "is eating");
		pthread_mutex_lock(&philo->mutex->time);
		philo->last_eat_time = save_now_time();
		pthread_mutex_unlock(&philo->mutex->time);
		ft_sleep(philo->env->time_to_eat);
		pthread_mutex_unlock(&philo->mutex->forks[philo->right]);
		pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
		return (0);
	}
	return (-1);
}

void	*start_thread(void *tmp)
{
	t_philo	*philo;

	philo = tmp;
	pthread_mutex_lock(&philo->mutex->time);
	philo->last_eat_time = save_now_time();
	pthread_mutex_unlock(&philo->mutex->time);
	while (1)
	{
		if (philo->env->num_times_must_eat > -1
			&& philo->eat_count == philo->env->num_times_must_eat)
		{
			pthread_mutex_lock(&philo->mutex->full[philo->id]);
			philo->full = 1;
			pthread_mutex_unlock(&philo->mutex->full[philo->id]);
			break ;
		}
		if (eat(philo) == -1)
			break ;
		printf_mutex(philo, "is sleeping");
		ft_sleep(philo->env->time_to_sleep);
		printf_mutex(philo, "is thinking");
	}
	return (NULL);
}

int	monitoring(t_philo *philos)
{
	int	ret;
	int	i;

	i = -1;
	ret = 1;
	pthread_mutex_lock(&philos[0].mutex->dead);
	if (philos[0].env->is_end)
	{
		pthread_mutex_unlock(&philos[0].mutex->dead);
		return (0);
	}	
	pthread_mutex_unlock(&philos[0].mutex->dead);
	while (++i < philos[0].env->num_philos)
	{
		if (check_dead(&philos[i]))
			return (0);
	}
	return (ret);
}

void	create_philo(t_philo *philos)
{
	int	i;

	philos[0].env->start_time = save_now_time();
	i = -1;
	while (++i < (*philos).env->num_philos)
		pthread_create(&philos[i].pthread, NULL, start_thread, &philos[i]);
	while (1)
		if (!monitoring(philos))
			break ;
}
