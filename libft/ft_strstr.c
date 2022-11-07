/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:28:40 by gkwon             #+#    #+#             */
/*   Updated: 2022/08/30 22:36:09 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*
#include <unistd.h>
#include <stdio.h>
int main ()
{
		char a[] = "my name is edwin";
		char b[] = "my name is edwin";
		char *ret = ft_strstr(a,b);
		printf("%s",ret);
		return 1;
}
*/
