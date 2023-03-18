/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/18 15:39:41 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*init_start(pthread_mutex_t **forks, t_argv my_argv, char **argv)
{
	t_philos	*philos;
	int			i;		

	i = 0;
	*forks = malloc(sizeof(pthread_mutex_t) * philo_num);
	philos = malloc(sizeof(t_philos) * philo_num);
	while (i < philo_num)
	{
		pthread_mutex_init(forks[i], NULL);
		pthread_create(philos[i].pthread, NULL, NULL, NULL);
		//philos[i].id = i;
		philos[i].left = i;
		philos[i].right = (i + 1) % philo_num;
	}
	return (philos);
}

int	init_argv(t_argv my_argv, char **argv)
{
	my_argv.number_of_philosophers = ft_atoi(argv[1]);
	my_argv.time_to_die = ft_atoi(argv[2]);
	my_argv.time_to_eat = ft_atoi(argv[3]);
	my_argv.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		my_argv.num_times_must_eat = ft_atoi(argv[5]);
}

int	print_error(char *error_str)
{
	printf("%s\n", error_str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philos		*philos;
	pthread_mutex_t	*forks;
	t_argv			my_argv;

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	init_argv(my_argv, **argv);
	philos = init_start(&forks, my_argv, argv);
	philo_start(&philos, my_argv, &forks);
}
