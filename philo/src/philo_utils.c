/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:17 by edwin             #+#    #+#             */
/*   Updated: 2023/03/27 01:53:24 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_deadbody(t_philo *philos)
{
	int	i;
	int	num_philos;

	num_philos = philos[0].env.num_philos;
	for (i = 0; i < num_philos; i++)
	{
		pthread_join(philos[i].pthread, NULL);
		pthread_mutex_destroy(&(philos[i].mutex->forks[i]));
	}
	free(philos[0].mutex->forks);
	pthread_mutex_destroy(&(philos[0].mutex->printf));
	pthread_mutex_destroy(&(philos[0].mutex->dead));
	pthread_mutex_destroy(&(philos[0].mutex->eat_count));
	free(philos);
}

// void	clean_deadbody(t_philo **philos)
// {
// 	int		i;
// 	int		num_philos;
// 	t_mutex	*tmp;

// 	tmp = (*philos)->mutex;
// 	num_philos = (*philos)->env.num_philos;
// 	// Free all resources for each philosopher
// 	i = 0;
// 	while (i < num_philos)
// 	{
// 		pthread_join(philos[i]->pthread, NULL);
// 		pthread_mutex_destroy(&(philos[i]->mutex->forks[i]));
// 		if (i == num_philos)
// 			free(philos[i]->mutex->forks);
// 		free(philos[i]);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&(tmp->printf));
// 	pthread_mutex_destroy(&(tmp->dead));
// 	pthread_mutex_destroy(&(tmp->eat_count));
// 	free(philos);
// }

// void	clean_deadbody(t_philo **philos)
// {
// 	int	i;

// 	i = -1;
// 	while ((philos)[++i])
// 	{
// 		if (i + 1 == (*philos)->env.num_philos)
// 		{
// 			pthread_mutex_destroy(&((*philos)->mutex->printf));
// 			pthread_mutex_destroy(&((*philos)->mutex->dead));
// 			pthread_mutex_destroy(&((*philos)->mutex->eat_count));
// 		}
// 		pthread_mutex_destroy(&((*philos)->mutex->forks[i]));
// 		free(&((*philos)->mutex->forks[i]));
// 		if (i + 1 == (*philos)->env.num_philos)
// 			free((*philos)->mutex->forks);
// 		pthread_join(philos[i]->pthread, NULL);
// 		free((philos)[i]);
// 	}
// 	free(philos);
// }

void	save_now_time(int *save_time)
{
	struct timeval	ms_time;

	gettimeofday(&ms_time, NULL);
	*save_time = ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000;
}

void	printf_mutex(t_philo *philo, char *str)
{
	save_now_time(&philo->env.now_time);
	if ((philo->env.now_time
			- philo->env.last_eat_time >= philo->env.time_to_die)
		|| philo->env.now_time
		- philo->env.start_time >= philo->env.time_to_die)
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