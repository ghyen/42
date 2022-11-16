/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:34:19 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/16 11:56:40 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned char	*tmp;
	unsigned int	len;

	len = size * count;
	ret = malloc(len);
	if (!ret)
		return (NULL);
	tmp = (unsigned char *)ret;
	while (len)
	{
		*tmp = 0;
		tmp++;
		len--;
	}
	return (ret);
}
