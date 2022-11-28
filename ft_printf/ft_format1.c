/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:32 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/28 19:59:31 by gkwon            ###   ########.fr       */
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
	if (!tmp)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, tmp, ft_strlen(tmp));
	return (ft_strlen(tmp));
}

int	format_p(va_list ap)
{
	return (ft_to_add((size_t)va_arg(ap, void *)));
}

int	format_d(va_list ap)
{
	char	*tmp;
	int		len;
	tmp = ft_itoa(va_arg(ap, int));
	write(1, tmp, ft_strlen(tmp));
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

int	format_i(va_list ap)
{
	char	*tmp;

	tmp = ft_itoa(va_arg(ap, int));
	write(1, tmp, ft_strlen(tmp));
	return (ft_strlen(tmp));
}
