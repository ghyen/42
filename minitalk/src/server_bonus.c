/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:06:33 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/16 20:26:44 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_server_info	g_info;

void	get_sig(int signo, siginfo_t *info, void *s)
{
	s = (void *)info;
	g_info.bits++;
	g_info.msg = g_info.msg << 1;
	if (signo == SIGUSR1)
		g_info.msg |= 1;
	else if (signo == SIGUSR2)
		g_info.msg |= 0;
	if (g_info.bits == 8)
	{
		if (g_info.msg == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
			g_info.msg = 0;
			g_info.bits = 0;
			return ;
		}
		else
		{
			ft_printf("%c", g_info.msg);
			//g_info.cnt++;
			//ft_printf("%d", g_info.cnt);
			g_info.bits = 0;
			g_info.msg = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("pid : %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = get_sig;
	g_info.msg = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
