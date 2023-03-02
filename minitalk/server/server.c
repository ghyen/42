/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:06:33 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/02 19:11:45 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	if (argc != 3)
	{
		ft_putstr_fd("invalid argument\n",2);
		exit(1);
	}
	pid = getpid();
	send_message(pid, );	
	return (0);
}
