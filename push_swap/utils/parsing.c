/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:29:32 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 23:48:26 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_digit(char **argv, int *size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			while (ft_isdigit(argv[i][j]))
			{
				flag = 1;
				j++;
			}
			if (flag == 0 && !ft_isdigit(argv[i][j]))
				return (0);
			if ((*size)++ >= 0 && argv[i][j] == ' ')
				j++;
		}
	}
	return (1);
}

int	valid_dup(int *array, long find, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (array[i++] == find || find > INT32_MAX || find < INT32_MIN)
			return (0);
	return (1);
}
