/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:56 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/16 18:34:14 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	s1l;
	unsigned int	s2l;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	p = (char *)malloc(s1l + s2l + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, s1l);
	ft_memmove(p + s1l, s2, s2l);
	p[s1l + s2l] = 0;
	return (p);
}
