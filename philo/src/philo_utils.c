/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:17 by edwin             #+#    #+#             */
/*   Updated: 2023/03/31 12:35:49 by gkwon            ###   ########.fr       */
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
	pthread_mutex_destroy(&((*philos)[0].mutex->time));
}

int	save_now_time(void)
{
	struct timeval	ms_time;

	gettimeofday(&ms_time, NULL);
	return (ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000);
}

//int	check_dead(t_philo *philo)
//{
//	int			ret;
//	int			now_time;
//	long long	diff;

//	pthread_mutex_lock(&philo->mutex->time);
//	if (philo->last_eat_time == 0)
//	{
//		pthread_mutex_unlock(&philo->mutex->time);
//		return (0);
//	}
//	now_time = save_now_time();
//	diff = now_time - philo->last_eat_time;
//	pthread_mutex_unlock(&philo->mutex->time);
//	if (diff >= philo->env->time_to_die)
//	{
//		pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
//		//printf("%dms %d %s\n", now_time - philo->env->start_time, philo->id,
//		//		"is died");
//		return (1);
//	}
//	pthread_mutex_lock(&philo->mutex->dead);
//	if (philo->env->is_end)
//		ret = 1;
//	else
//		ret = 0;
//	pthread_mutex_unlock(&philo->mutex->dead);
//	return (ret);
//}

int	check_dead(t_philo *philo)
{
	int			now_time;
	long long	diff;
	int			ret;

	ret = 0;
	pthread_mutex_lock(&philo->mutex->dead);
		if(philo->env->is_end == 1)
			ret = 1;
	pthread_mutex_unlock(&philo->mutex->dead);
	if (ret)
		return (ret);
	pthread_mutex_lock(&philo->mutex->time);
	if (philo->last_eat_time)
	{
		now_time = save_now_time();
		diff = now_time - philo->last_eat_time;
		pthread_mutex_unlock(&philo->mutex->time);
		if (diff >= philo->env->time_to_die)
		{
			pthread_mutex_lock(&philo->mutex->dead);
			philo->env->is_end = 1;
			pthread_mutex_unlock(&philo->mutex->dead);
			pthread_mutex_lock(&philo->mutex->printf);
			printf("%d %d %s\n", now_time - philo->env->start_time,
				philo->id, "is died");
			pthread_mutex_unlock(&philo->mutex->printf);
			pthread_mutex_unlock(&philo->mutex->forks[philo->left]);
			ret = 1;
		}
	}
	return (ret);
}

void	printf_mutex(t_philo *philo, char *str)
{
	int	now_time;

	if (check_dead(philo))
	{
		pthread_mutex_lock(&philo->mutex->dead);
		if (!philo->env->is_end)
		{
			philo->env->is_end = 1;
			now_time = save_now_time();
			pthread_mutex_lock(&philo->mutex->printf);
			printf("%d %d %s\n", now_time - philo->env->start_time,
			philo->id, "is died");
			pthread_mutex_unlock(&philo->mutex->printf);
		}
		pthread_mutex_unlock(&philo->mutex->dead);
	}
	else
	{
		pthread_mutex_lock(&philo->mutex->printf);
		now_time = save_now_time();
		printf("%d %d %s\n", now_time - philo->env->start_time, philo->id,
				str);
		pthread_mutex_unlock(&philo->mutex->printf);
	}
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
