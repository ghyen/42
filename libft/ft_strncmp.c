/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:18 by gkwon             #+#    #+#             */
/*   Updated: 2022/08/31 01:28:36 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2)
	{
		if (n == 0)
			return (0);
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			if ((unsigned char)*s1 > (unsigned char)*s2)
				return (1);
			else if ((unsigned char)*s1 < (unsigned char)*s2)
				return (-1);
		}
		s1++;
		s2++;
		n--;
	}
	if ((unsigned char)*s1 > (unsigned char)*s2)
		return (1);
	else if ((unsigned char)*s1 < (unsigned char)*s2)
		return (-1);
	return (0);
}

/*
	#include <stdio.h>
	#include <string.h>
	int main()
	{
		char s1[] = "BlockDMask";
		char s2[] = "Block";
		char s3[] = "BlockAAAAA";
		s1[5] = -10;
		s2[5] = 10;
		printf("%d\n",ft_strncmp(s1, s2, 6));
		printf("%d",strncmp(s1, s2, 6));	
	}
*/
