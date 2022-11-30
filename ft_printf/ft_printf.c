/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:03:03 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 14:36:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	redirection(const char format, va_list ap)
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
	int		i;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (write(1, format, 1) == M_ERROR)
				return (M_ERROR);
			len++;
		}
		else
		{
			len += redirection(*++format, ap);
			i++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
