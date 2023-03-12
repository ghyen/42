/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:06:33 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/11 19:48:08 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../minitalk.h"

void	get_sig(int signo, siginfo_t *info, void *s)
{
	(void)s;

}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("pid : %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = get_sig;
	sig.sa_sigaction = get_sig;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
