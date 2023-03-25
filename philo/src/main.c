/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/24 20:28:16 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*init_start(t_mutex *mutex_info, char **argv)
{
	t_philo	*philo;
	int			i;
	int			num_philos;

	i = -1;
	num_philos = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * num_philos);
	pthread_mutex_init(&(mutex_info->printf), NULL);
	pthread_mutex_init(&(mutex_info->dead), NULL);
	pthread_mutex_init(&(mutex_info->eat_count), NULL);
	mutex_info->forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	while (++i < num_philos)
		pthread_mutex_init(&(mutex_info->forks[i]), NULL);
	i = -1;
	while (++i < num_philos)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % num_philos;
		philo[i].env.num_philos = num_philos;
		philo[i].env.time_to_die = ft_atoi(argv[2]);
		philo[i].env.time_to_eat = ft_atoi(argv[3]);
		philo[i].env.time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].env.num_times_must_eat = ft_atoi(argv[5]);
		philo[i].mutex = mutex_info;
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
	t_mutex		mutex_info;

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	philo = init_start(&mutex_info, argv);
	create_philo(&philo);
	return (0);
}
