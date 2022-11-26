/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:03:03 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/26 17:49:18 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list ap)
{
	char	tmp;

	tmp = va_arg(ap, int);
	write(1, &tmp, sizeof(char));
	return (1);
}

int	format_s(va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	write(1, tmp, ft_strlen(tmp));
	return (ft_strlen(tmp) + 1);
}

int	format_p(va_list ap)
{
	int	tmp;

	tmp = va_arg(ap, void *);
	ft_dec_to_hex((long long)tmp);
	return (ft_strlen(tmp) + 1);
}

int	format_d(va_list ap)
{
	int	tmp;

	tmp = va_arg(ap, int);
	write(1, ft_itoa(tmp), ft_strlen(ft_itoa(tmp)));
	return (ft_strlen(ft_itoa(tmp)) + 1);
}

int	format_i(va_list ap)
{
	long long	tmp;

	tmp = va_arg(ap, int);
	write(1, ft_itoa(tmp), ft_strlen(ft_itoa(tmp)));
	return (ft_strlen(ft_itoa(tmp)) + 1);
}

int	redirection(const char format, va_list ap)
{
	if (format == 'c')
		return (format_c(ap));
	else if (format == 's')
		return (format_s(ap));
	else if (format == 'p')
		return (format_p(ap));
	else if (format == 'd')
		return (format_d(ap));
	else if (format == 'i')
		return (format_i(ap));
	//else if (format == 'u')
	//	return (format_u(ap));
	//else if (format == 'x')
	//	return (format_x(ap));
	//else if (format == 'X')
	//	return (format_X(ap));
	//else if (format == '%')
	//	return (format_ps(ap));
	return (0);
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
			write(1, &format, 1);
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
