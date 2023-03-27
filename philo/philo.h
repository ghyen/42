/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:31 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/27 01:16:49 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_env
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_times_must_eat;
	int			start_time;
    int         last_eat_time;
    int         now_time;
}				t_env;

typedef struct s_mutex
{
	pthread_mutex_t	eat_count;
	pthread_mutex_t	printf;
	pthread_mutex_t	dead;
	pthread_mutex_t	*forks;
}				t_mutex;

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
    t_mutex     *mutex;
}				t_philo;

/* ===============./src=============== */

t_philo	*init_start(t_mutex *mutex_info, char **argv);
int		print_error(char *error_str);
void	clean_deadbody(t_philo *philos);
void	save_now_time(int *save_time);
void	printf_mutex(t_philo *philo, char *str);
int		ft_atoi(const char *str);
void	eat(t_philo *philo);
void	*start_thread(void *tmp);
int		monitoring(t_philo **philos);
void	create_philo(t_philo **philos);

#endif
