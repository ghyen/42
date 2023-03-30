/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/30 22:29:30 by gkwon            ###   ########.fr       */
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
	mutex_info->forks = malloc(sizeof(pthread_mutex_t) * env->num_philos);
	mutex_info->full = malloc(sizeof(pthread_mutex_t) * env->num_philos);
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
	}
	return (philo);
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

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	env.num_philos = ft_atoi(argv[1]);
	env.time_to_die = ft_atoi(argv[2]);
	env.time_to_eat = ft_atoi(argv[3]);
	env.time_to_sleep = ft_atoi(argv[4]);
	env.is_end = 0;
	if (argc == 6)
		env.num_times_must_eat = ft_atoi(argv[5]);
	philo = init_start(&mutex_info, &env);
	create_philo(&philo);
	return (0);
}
