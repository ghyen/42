/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:08:28 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/18 23:18:41 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		tmp;
	int		cnt;
	int		neg;
	
	neg = 0;
	cnt = 0;
	tmp = n;
	if (n < 0)
		neg = 1;
	while (tmp)
	{
		tmp /= 10;
		cnt++;
	}
	ret = (char *)malloc(cnt + 1 + neg);
	if (neg)
	{
		ret[0] = '-';
		ret++;
		n *= -1;
	}
	while (n)
	{
		
	}
}
