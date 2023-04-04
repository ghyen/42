/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/04/05 02:15:55 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_philo	*init_start(t_mutex *mutex_info, t_env *env)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * env->num_philos);
	pthread_mutex_init(&(mutex_info->printf), NULL);
	pthread_mutex_init(&(mutex_info->dead), NULL);
	pthread_mutex_init(&(mutex_info->time), NULL);
	while (++i < env->num_philos)
	{
		pthread_mutex_init(&(mutex_info->forks[i]), NULL);
		pthread_mutex_init(&(mutex_info->full[i]), NULL);
	}
	i = -1;
	while (++i < env->num_philos)
	{
		philo[i].id = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % env->num_philos;
		philo[i].eat_count = 0;
		philo[i].mutex = mutex_info;
		philo[i].env = env;
		philo[i].last_eat_time = 0;
	}
	return (philo);
}

void	ft_sleep(int msec)
{
	int	end_time;

	end_time = save_now_time() + msec;
	while (save_now_time() < end_time)
		usleep(100);
}

int	save_now_time(void)
{
	struct timeval	ms_time;

	gettimeofday(&ms_time, NULL);
	return (ms_time.tv_sec * 1000 + ms_time.tv_usec / 1000);
}

int	print_error(char *error_str)
{
	printf("%s\n", error_str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_mutex	mutex_info;
	t_env	env;

	memset(&env, 0, sizeof(t_env));
	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	env.num_philos = ft_atoi(argv[1]);
	env.time_to_die = ft_atoi(argv[2]);
	env.time_to_eat = ft_atoi(argv[3]);
	env.time_to_sleep = ft_atoi(argv[4]);
	env.is_end = 0;
	env.num_times_must_eat = -1;
	if (argc == 6)
		env.num_times_must_eat = ft_atoi(argv[5]);
	mutex_info.forks = malloc(sizeof(pthread_mutex_t) * env.num_philos);
	mutex_info.full = malloc(sizeof(pthread_mutex_t) * env.num_philos);
	philo = init_start(&mutex_info, &env);
	create_philo(philo);
	clean_deadbody(&philo);
	return (0);
}
