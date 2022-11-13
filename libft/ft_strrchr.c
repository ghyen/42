/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:37 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/13 22:20:12 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (c == *s)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
