/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:37 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/15 21:31:23 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	cc;

	cc = c;
	tmp = 0;
	if (cc == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (cc == *s)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
