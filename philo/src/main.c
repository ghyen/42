/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:22 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/18 03:51:28 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_t	*init_start(char *philo_num)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philos) * ft_atoi(philo_num));
	while (i < ft_atoi(philo_num))
	{
		pthread_create(philos[i].pthread, NULL, );
		//philos[i].id = i;
		philos[i].left = i;
		philos[i].right = (i + 1) % ft_atoi(philo_num);
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
	t_philos	*philos;

	if (argc != 5 && argc != 6)
		return (print_error("error argc"));
	philos = init_start(argv[1]);
	philo_start(&philos, argv);
}
