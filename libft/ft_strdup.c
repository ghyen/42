/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:58:30 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/07 11:21:39 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*ret;

	len = 0;
	while (src[len])
		len++;
	ret = (char *)malloc(sizeof(char) * len + 1);
	*ret = 0;
	while (*src)
	{
		*ret = *src;
		ret++;
		src++;
	}
	*ret = 0;
	return (ret - len);
}
