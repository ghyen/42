/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:22:16 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/13 17:49:02 by gkwon            ###   ########.fr       */
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
	while (*src && dstsize != 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = 0;
	return (d_len + s_len);
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
  char str1[100] = "bbb";
  char str2[100] = "aaaaa";
  printf("%lu\n", ft_strlcat(str2, str1, 6));
  printf("%lu\n", strlcat(str2, str1, 6));
  //str2[5] = '\0';
  printf("%s",str2);
  return 0;
}
*/
