/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:22:16 by gkwon             #+#    #+#             */
/*   Updated: 2022/08/30 20:06:00 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len >= size)
		return (s_len + size);
	while (*dest)
		dest++;
	size -= d_len;
	while (*src && size != 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
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
