/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/18 20:17:46 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*init_start(t_mutex *mutex_info, t_env my_env, char **argv)
{
	t_philos	*philos;
	int			i;

	i = 0;
	my_env.num_philos = ft_atoi(argv[1]);
	my_env.time_to_die = ft_atoi(argv[2]);
	my_env.time_to_eat = ft_atoi(argv[3]);
	my_env.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		my_env.num_times_must_eat = ft_atoi(argv[5]);
	mutex_info->forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	philos = malloc(sizeof(t_philos) * num_philos);
	while (i < num_philos)
	{
		pthread_mutex_init(fork, NULL);
		philos[i].id = i + 1;
		philos[i].left = i;
		philos[i].right = (i + 1) % num_philos;
	}
	pthread_mutex_init(mutex_info->printf, NULL);
	pthread_mutex_init(mutex_info->dead, NULL);
	pthread_mutex_init(mutex_info->fork, NULL);
	return (philos);
}

int	print_error(char *error_str)
{
	printf("%s\n", error_str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philos		*philos;
	t_mutex			mutex_info;
	t_env			my_env;

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	t_env.start_time = gettimeofday();
	philos = init_start(&mutex_info, my_env, argv);
	philo_start(&philos, my_env, &mutex_info);
}
