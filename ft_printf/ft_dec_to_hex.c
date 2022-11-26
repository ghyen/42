/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:30:28 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/26 17:50:07 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vaild_check(char *base)
{
	char	tmp[1024];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 1024)
		tmp[i++] = 0;
	i = 0;
	if (*base == '\0' || base[1] == '\0')
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		while (j <= i)
			if (*base == tmp[j++])
				return (0);
		j = 0;
		tmp[i++] = *base;
		base++;
	}
	return (1);
}

int	check_m(long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	return (0);
}

void	cal_and_print(long long nb, char *tmp, char *base, int j)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	while (nb != 0)
	{
		tmp[j++] = base[nb % i];
		nb /= i;
	}
	while (--j != -1)
		write(1, &tmp[j], 1);
}

void	ft_dec_to_hex(int nb)
{
	char		tmp[1024];
	int			i;
	int			j;
	char		*base;
	
	base = "0123456789abcdef";
	if (!vaild_check(base))
		return ;
	j = 0;
	i = 0;
	while (i < 1024)
		tmp[i++] = 0;
	i = 0;
	if (check_m(nb))
		nb *= -1;
	if (nb == 0)
		write(1, &base[0], 1);
	else
		cal_and_print(nb, tmp, base, j);
}
