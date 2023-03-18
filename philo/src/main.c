/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/18 16:07:28 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*init_start(pthread_mutex_t **forks, t_argv my_argv, char **argv)
{
	t_philos	*philos;
	int			i;		

	i = 0;
	my_argv.num_philos = ft_atoi(argv[1]);
	my_argv.time_to_die = ft_atoi(argv[2]);
	my_argv.time_to_eat = ft_atoi(argv[3]);
	my_argv.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		my_argv.num_times_must_eat = ft_atoi(argv[5]);
	*forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	philos = malloc(sizeof(t_philos) * num_philos);
	while (i < num_philos)
	{
		pthread_mutex_init(forks[i], NULL);
		pthread_create(philos[i].pthread, NULL, NULL, NULL);
		//philos[i].id = i;
		philos[i].left = i;
		philos[i].right = (i + 1) % num_philos;
	}
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
	pthread_mutex_t	*forks;
	t_argv			my_argv;

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	philos = init_start(&forks, my_argv, argv);
	philo_start(&philos, my_argv, &forks);
}
