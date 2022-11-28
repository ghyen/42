/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:11:00 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/28 20:22:46 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	cal_and_print(unsigned int nb, char *tmp, char *base)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (base[i])
		i++;
	while (nb != 0)
	{
		tmp[j++] = base[nb % i];
		nb /= i;
	}
	len = j;
	while (--j != -1)
		write(1, &tmp[j], 1);
	return (len);
}

size_t	ft_to_hex(unsigned int nb, int letter)
{
	char	tmp[1024];
	char	*base;

	if (letter == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	else
		return (cal_and_print(nb, tmp, base));
}
