/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:23:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/26 16:52:26 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_address(unsigned long addr)
{
	char	*base;
	char	buffer[17];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (addr)
	{
		buffer[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	while (i < 16)
	{
		buffer[i] = '0';
		i++;
	}
	i--;
	while (i + 1)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}


void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	p;
	unsigned int	offset;

	offset = 0;
	p = (unsigned long)addr;
	(void)size;
	while (offset < size)
	{
		ft_print_address(p + offset);
		offset += 16;
	}
	return (addr);
}
