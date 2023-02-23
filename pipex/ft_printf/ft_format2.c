/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:56:17 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 21:41:51 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(va_list ap)
{
	char	*tmp;
	int		len;

	tmp = ft_unsigned_itoa(va_arg(ap, int));
	if (!tmp)
		return (M_ERROR);
	if (write(1, tmp, ft_strlen(tmp)) == M_ERROR)
	{
		free(tmp);
		return (M_ERROR);
	}
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

int	format_x_lower(va_list ap)
{
	return (ft_to_hex(va_arg(ap, int), 1));
}

int	format_x_upper(va_list ap)
{
	return (ft_to_hex(va_arg(ap, int), 2));
}

int	format_ps(void)
{
	if (write(1, "%", 1) == M_ERROR)
		return (M_ERROR);
	return (1);
}
