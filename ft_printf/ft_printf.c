/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:03:03 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 21:50:17 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	redirection(const char format, va_list ap)
{
	if (format == 'c')
		return (format_c(ap));
	else if (format == 's')
		return (format_s(ap));
	else if (format == 'p')
		return (format_p(ap));
	else if (format == 'd' || format == 'i')
		return (format_d(ap));
	else if (format == 'u')
		return (format_u(ap));
	else if (format == 'x')
		return (format_x_lower(ap));
	else if (format == 'X')
		return (format_x_upper(ap));
	else if (format == '%')
		return (format_ps());
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		tmp;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format != '%' && ++len)
		{
			if (write(1, format, 1) == M_ERROR)
				return (M_ERROR);
		}
		else
		{
			tmp = redirection(*++format, ap);
			if (tmp == M_ERROR)
				return (M_ERROR);
			else
				len += tmp;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
