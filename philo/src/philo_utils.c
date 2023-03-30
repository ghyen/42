/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:17 by edwin             #+#    #+#             */
/*   Updated: 2023/03/30 23:02:40 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_deadbody(t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < philos[0]->env->num_philos)
	{
		pthread_join((*philos)[i].pthread, NULL);
		pthread_mutex_destroy(&((*philos)[i].mutex->forks[i]));
		pthread_mutex_destroy(&((*philos)[i].mutex->full[i]));
	}
	free((*philos)[0].mutex->forks);
	pthread_mutex_destroy(&((*philos)[0].mutex->printf));
	pthread_mutex_destroy(&((*philos)[0].mutex->dead));
}

void	save_now_time(int *save_time)
{
	struct timeval	ms_time;

	gettimeofday(&ms_time, NULL);
	*save_time = ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000;
}

int	check_dead(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->mutex->dead);
	if (philo->env->is_end)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&philo->mutex->dead);
	return (ret);
}

void	printf_mutex(t_philo *philo, char *str)
{
	if (check_dead(philo))
		return ;
	save_now_time(&philo->now_time);
	if (philo->now_time	- philo->last_eat_time >= philo->env->time_to_die)
	{
		if (check_dead(philo))
			return ;
		pthread_mutex_lock(&philo->mutex->printf);
		printf("%dms %d %s\n", philo->now_time - philo->env->start_time,
			philo->id, "is died");
		pthread_mutex_lock(&philo->mutex->dead);
		philo->env->is_end = 1;
		pthread_mutex_unlock(&philo->mutex->dead);
		pthread_mutex_unlock(&philo->mutex->printf);
		return ;
	}
	pthread_mutex_lock(&philo->mutex->printf);
	printf("%dms %d %s\n", philo->now_time - philo->env->start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->mutex->printf);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	long long	tmp;
	int			flag;

	(void)tmp;
	ret = 0;
	flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = ret;
		ret *= 10;
		ret += (*str++ - '0');
	}
	return (ret * flag);
}
