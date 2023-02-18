/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:07:24 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/19 06:11:24 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	n = (n % 10) + '0';
	write(fd, &n, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}