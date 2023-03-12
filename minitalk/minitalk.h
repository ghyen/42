/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:10:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/11 19:35:00 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_client_info
{
	char	*str;
	int		bits_cnt;
	pid_t	server_pid;
}			t_client_info;

typedef struct s_server_info
{
	int		client_pid;

}			t_server_info;

#endif
