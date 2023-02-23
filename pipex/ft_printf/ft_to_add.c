/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:30:28 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 20:34:12 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	cal_and_print(size_t nb, char *tmp, char *base)
{
	int		i;
	int		j;
	size_t	len;

	j = 0;
	i = 0;
	len = 0;
	while (base[i])
		i++;
	if (nb == 0)
		tmp[j++] = '0';
	while (nb != 0)
	{
		tmp[j++] = base[nb % i];
		nb /= i;
	}
	tmp[j++] = 'x';
	tmp[j] = '0';
	len += j + 1;
	while (j != -1)
		if (write(1, &tmp[j--], 1) == M_ERROR)
			return (M_ERROR);
	return (len);
}

size_t	ft_to_add(size_t nb)
{
	char	tmp[18];
	char	*base;

	base = "0123456789abcdef";
	return (cal_and_print(nb, tmp, base));
}
