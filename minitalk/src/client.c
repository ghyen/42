/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:06:40 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/13 22:43:40 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_client_info	g_info;

void	send_message(int signo, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;
	(void)info;
	(void)s;

	if (signo == SIGUSR2)
	{
		write(1, "hello\n", 6);
		exit(0);
	}
	i = 0;
	bit = 8;
	while (g_info.str[i] != '\0')
	{
		while (--bit >= 0)
		{
			if ((g_info.str[i] >> bit) & 1)
				kill(g_info.server_pid, SIGUSR1);
			else
				kill(g_info.server_pid, SIGUSR2);
			usleep(300);
		}
		bit = 8;
		i++;
	}
	if (g_info.str[i] == '\0')
	{
		while (bit-- > 0)
		{
			kill(g_info.server_pid, SIGUSR2);
			usleep(300);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_putstr_fd("invalid argument\n", 2);
		exit(1);
	}
	g_info.server_pid = ft_atoi(argv[1]);
	g_info.str = argv[2];
	g_info.bits_cnt = 0;
	sig.sa_sigaction = send_message;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_message(0, NULL, NULL);
	return (0);
}
