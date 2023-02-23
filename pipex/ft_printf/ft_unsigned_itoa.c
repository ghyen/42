/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:59 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/28 17:04:20 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*result_str;

	len = count_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	result_str = malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (0);
	result_str[len--] = 0;
	while (n)
	{
		result_str[len--] = ('0' + (n % 10));
		n /= 10;
	}
	return (result_str);
}
