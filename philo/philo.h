/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:21:31 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/31 17:35:21 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_env
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_times_must_eat;
	int			is_end;
	int			start_time;
}				t_env;

typedef struct s_mutex
{
	pthread_mutex_t	*full;
	pthread_mutex_t	printf;
	pthread_mutex_t	dead;
	pthread_mutex_t	time;
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
    int         last_eat_time;
    int         now_time;
	t_env		*env;
    t_mutex     *mutex;
}				t_philo;

/* ===============./src=============== */

void	ft_sleep(int msec);
int		print_error(char *error_str);
int		eat(t_philo *philo);
void	*start_thread(void *tmp);
int		is_all_full(t_philo *philos);
//int	monitoring(t_philo **philos);
//			if (check_dead(philos[i]));
//				ret = 0;
//			i++;
//		}
//		if (is_all_full(philos));
//			ret = 0;
//		return (ret);
//}

//void		create_philo(t_philo **philos);
//		if (is_all_full(philos));
//			ret = 0;
//		return (ret);
//}

//void		create_philo(t_philo **philos);
//void	create_philo(t_philo **philos);
//			pthread_create(&(*philos)[i].pthread, NULL, start_thread,
//				(void *)&(*philos)[i]);
//		while (monitoring(philos));
//			;
//		clean_deadbody(philos);
//}

int		monitoring(t_philo *philos);
//		while (monitoring(philos));
//			;
//		clean_deadbody(philos);
//}

/* ===============./src=============== */

void	ft_sleep(int msec);
int		print_error(char *error_str);
int		eat(t_philo *philo);
void	*start_thread(void *tmp);
int		is_all_full(t_philo *philos);
//int	monitoring(t_philo **philos);
//			if (check_dead(philos[i]));
//				ret = 0;
//			i++;
//		}
//		if (is_all_full(philos));
//			ret = 0;
//		return (ret);
//}

//void		create_philo(t_philo **philos);
//		if (is_all_full(philos));
//			ret = 0;
//		return (ret);
//}

//void		create_philo(t_philo **philos);
//void	create_philo(t_philo **philos);
//			pthread_create(&(*philos)[i].pthread, NULL, start_thread,
//				(void *)&(*philos)[i]);
//		while (monitoring(philos));
//			;
//		clean_deadbody(philos);
//}

int		monitoring(t_philo *philos);
//		while (monitoring(philos));
//			;
//		clean_deadbody(philos);
//}

int		monitoring(t_philo *philos);
int		monitoring(t_philo *philos);
void	create_philo(t_philo *philos);
void	clean_deadbody(t_philo **philos);
int		save_now_time(void);
int		check_dead(t_philo *philo);
void	printf_mutex(t_philo *philo, char *str);
int		ft_atoi(const char *str);

#endif
