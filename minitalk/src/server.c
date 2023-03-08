/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:06:33 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/07 17:30:47 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_message(pid_t pid, char *msg)
{
	static int	i;
	static int	bit;
	static int	kill_count;

	i = 0;
	bit = 8;
	kill_count = 0;
	while (msg[i] != '\0')
	{
		while (--bit >= 0)
		{
			if ((msg[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			kill_count++;
		}
		bit = 8;
		i++;
	}
	ft_putnbr_fd(kill_count, 1);
	ft_putstr_fd("\n", 1);
	if (msg[i] == '\0')
	{
		while (bit-- > 0)
		{
			kill(pid, SIGUSR2);
			usleep(250);
		}
		pajjuse();
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("pid : %d\n", getpid());
	
	return (0);
}
