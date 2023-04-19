/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:31 by gkwon             #+#    #+#             */
/*   Updated: 2023/04/07 18:33:30 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_env
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	int				is_end;
	int				start_time;
}					t_env;

typedef struct s_mutex
{
	pthread_mutex_t	*full;
	pthread_mutex_t	printf;
	pthread_mutex_t	dead;
	pthread_mutex_t	time;
	pthread_mutex_t	*forks;
}					t_mutex;

typedef struct s_philo
{
	pthread_t		pthread;
	int				left;
	int				right;
	int				eat_count;
	int				id;
	int				full;
	long long		last_eat_time;
	long long		now_time;
	t_env			*env;
	t_mutex			*mutex;
}					t_philo;

/* ===============./src=============== */

void	ft_sleep(int msec);
int		save_now_time(void);
int		is_valid_av(int ac, t_env *env);
int		eat(t_philo *philo);
void	*start_thread(void *tmp);
int		monitoring(t_philo *philos);
void	create_philo(t_philo *philos);
void	clean_deadbody(t_philo **philos);
int		check_dead2(t_philo *philo);
int		check_dead(t_philo *philo);
void	printf_mutex(t_philo *philo, char *str);
int		ft_atoi(const char *str);

#endif
