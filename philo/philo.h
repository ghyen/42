/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:31 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/19 17:59:47 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PIHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	pthread;
	int			left;
	int			right;
	int			eat_count;
	int			id;
	int			full;
	int			dead;
	t_env		env;
}				t_philo;

typedef struct s_env
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_times_must_eat;
	int			start_time;
	int			now_time;
}				t_env;

typedef struct s_mutex
{
	pthread_mutex_t	eat_count;
	pthread_mutex_t	printf;
	pthread_mutex_t	dead;
	pthread_mutex_t	*forks;
}				t_mutex;

#endif