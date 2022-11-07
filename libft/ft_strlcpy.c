/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:23:26 by gkwon             #+#    #+#             */
/*   Updated: 2022/09/15 05:04:24 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (*src)
	{
		src++;
		i++;
	}
	src -= i;
	while ((size - 1) != 0 && *src && !(size == 0))
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (i);
}
/*
#include <stdio.h>

int main()
{
    char s1[10] = "Hello";    // 크기가 10인 char형 배열을 선언하고 문자열 할당
    char s2[10];              // 크기가 10인 char형 배열을 선언

    ft_strlcpy(s2, s1, 0);        // s1의 문자열을 s2로 복사
    
    printf("%s\n", s2);    // Hello

    return 0;
}
*/
