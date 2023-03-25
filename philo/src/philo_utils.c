/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:17 by edwin             #+#    #+#             */
/*   Updated: 2023/03/24 20:29:32 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_deadbody(t_philo **philos)
{
	int	i;

	i = -1;
	while ((philos)[++i])
	{
		if (i + 1 == (*philos)->env.num_philos)
		{
			pthread_mutex_destroy(&((*philos)->mutex->printf));
			pthread_mutex_destroy(&((*philos)->mutex->dead));
			pthread_mutex_destroy(&((*philos)->mutex->eat_count));
		}
		pthread_mutex_destroy(&((*philos)->mutex->forks[i]));
		free(&((*philos)->mutex->forks[i]));
		if (i + 1 == (*philos)->env.num_philos)
			free((*philos)->mutex->forks);
		pthread_join(philos[i]->pthread, NULL);
		free((philos)[i]);
	}
	free(philos);
}

void	save_now_time(int *save_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*save_time = time.tv_usec;
}

void	printf_mutex(t_philo *philo, char *str)
{
	save_now_time(&philo->env.now_time);
	if ((philo->env.now_time
			- philo->env.last_eat_time > philo->env.time_to_die) || philo->dead)
	{
		philo->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->mutex->printf);
	save_now_time(&philo->env.now_time);
	printf("%dms %d %s\n", philo->env.now_time - philo->env.start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->mutex->printf);
}

int	ft_atoi(const char *str)
{
	long long ret;
	long long tmp;
	int flag;

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