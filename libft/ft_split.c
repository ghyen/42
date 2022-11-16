/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:49:10 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/16 23:36:54 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		cnt;
	int		j;
	int		t_len;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (*s == c)
			cnt++;
		i++;
	}
	t_len = cnt;
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (*s)
	{
		cnt = 0;
		while (s[cnt] != c && s[cnt])
			cnt++;
		ret[j] = (char *)malloc(sizeof(char) * (cnt + 1));
		ft_memmove(ret[j], s, cnt);
		ret[cnt] = 0;
		s += cnt + 1;
	}
	ret[t_len] = 0;
	return (ret);
}
