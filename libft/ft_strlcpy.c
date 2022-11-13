/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:23:26 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/13 20:56:09 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (*src)
	{
		src++;
		i++;
	}
	if (dstsize == 0)
		return (i);
	src -= i;
	while (dstsize > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = 0;
	return (i);
}
