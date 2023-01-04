/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:22:16 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/20 17:45:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (*dst)
		dst++;
	dstsize -= d_len;
	while (*src && dstsize-- != 1)
		*dst++ = *src++;
	*dst = 0;
	return (d_len + s_len);
}
