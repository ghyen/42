/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:14:17 by edwin             #+#    #+#             */
/*   Updated: 2023/03/19 18:41:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	save_now_time(int *save_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	&save_time = time.tv_usec;
}

int	printf_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(printf);
	save_now_time(philo->env.now_time);
	printf("%dms %d %s\n", philo->env.now_time - philo->env.start_time,
		philo->id, str);
	pthread_mutex_unlock(printf);
}

int	ft_atoi(const char *str)
{
	long long ret;
	long long tmp;
	int flag;

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