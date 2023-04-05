/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/04/05 16:43:23 by gkwon            ###   ########.fr       */
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

int	is_valid_av(int ac, t_env *env)
{
	int	is_valid;

	is_valid = 1;
	env->is_end = 0;
	if (env->num_philos == -1 || env->time_to_die == -1 || \
		env->time_to_eat == -1 || env->time_to_sleep == -1)
		is_valid = 0;
	if (ac == 6 && env->num_times_must_eat == -1)
		is_valid = 0;
	if (!is_valid)
	{
		printf("%s\n", "error argc");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_mutex	mutex_info;
	t_env	env;

	if (argc != 5 && argc != 6)
	{
		printf("error argc");
		return (1);
	}
	memset(&env, 0, sizeof(t_env));
	env.num_philos = ft_atoi(argv[1]);
	env.time_to_die = ft_atoi(argv[2]);
	env.time_to_eat = ft_atoi(argv[3]);
	env.time_to_sleep = ft_atoi(argv[4]);
	env.num_times_must_eat = -1;
	if (argc == 6)
		env.num_times_must_eat = ft_atoi(argv[5]);
	if (!is_valid_av(argc, &env))
		return (1);
	mutex_info.forks = malloc(sizeof(pthread_mutex_t) * env.num_philos);
	mutex_info.full = malloc(sizeof(pthread_mutex_t) * env.num_philos);
	philo = init_start(&mutex_info, &env);
	create_philo(philo);
	clean_deadbody(&philo);
	return (0);
}
