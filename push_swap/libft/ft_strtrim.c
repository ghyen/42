/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:52:08 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/16 19:45:48 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		start;
	int		end;

	start = 0;
	if (!*set || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end <= start)
			return (ft_strdup(""));
		end--;
	}
	p = (char *)malloc(end - start + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1 + start, end - start);
	p[end - start] = 0;
	return (p);
}
