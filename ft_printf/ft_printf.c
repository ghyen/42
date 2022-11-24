/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:03:03 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/24 17:13:53 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_c(va_list ap)
{
	char	tmp;
	
	tmp = va_arg(ap, char);
	write(1, tmp, sizeof(char));
	va_copy(ap, tmp);
}

void	format_s(va_list ap)
{
	va_list	tmp;

	write(1, ap, sizeof(char));
	tmp = va_arg(ap, char);
	va_copy(ap, tmp);
}

int	redirection(const char format, va_list ap)
{
	if (format == 'c')
		format_c(ap);
	else if (format == 's')
		format_s(ap);
	else if (format == 'p')
		format_p(ap);
	else if (format == 'd')
		format_d(ap);
	else if (format == 'i')
		format_i(ap);
	else if (format == 'u')
		format_u(ap);
	else if (format == 'x')
		format_x(ap);
	else if (format == 'X')
		format_X(ap);
	else if (format == '%')
		format_ps(ap);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_strat(ap, format);
	i = 0;
	len = 0;
	while (*format)
	{
		if (*format != '%')
			wrtie(1, &format, 1);
		else
		{
			redirection(++*format, ap);
			format++;
			i++;
		}
		format++;
		len++;
	}
	va_end(ap);
	return (len);
}
