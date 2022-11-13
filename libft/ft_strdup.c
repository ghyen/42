/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:58:30 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/13 18:24:33 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;

	len = 0;
	while (s1[len])
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	*ret = 0;
	while (*s1)
	{
		*ret = (char)*s1;
		ret++;
		s1++;
	}
	*ret = 0;
	return (ret - len);
}
