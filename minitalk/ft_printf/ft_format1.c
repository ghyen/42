/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:32 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 21:40:49 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list ap)
{
	char	tmp;

	tmp = va_arg(ap, int);
	if (write(1, &tmp, sizeof(char)) == M_ERROR)
		return (M_ERROR);
	return (1);
}

int	format_s(va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	if (!tmp)
	{
		if (write(1, "(null)", 6) == M_ERROR)
			return (M_ERROR);
		return (6);
	}
	if (write(1, tmp, ft_strlen(tmp)) == M_ERROR)
		return (M_ERROR);
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
	if (!tmp)
		return (M_ERROR);
	len = ft_strlen(tmp);
	if (write(1, tmp, ft_strlen(tmp)) == M_ERROR)
	{
		free(tmp);
		return (M_ERROR);
	}
	free(tmp);
	return (len);
}
