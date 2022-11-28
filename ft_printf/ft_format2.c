/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:56:17 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/28 20:17:55 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(va_list ap)
{
	char	*tmp;
	int		len;

	tmp = ft_unsigned_itoa(va_arg(ap, int));
	write(1, tmp, ft_strlen(tmp));
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
	write(1, "%", 1);
	return (1);
}
