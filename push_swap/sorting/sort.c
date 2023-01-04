/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 02:11:31 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	buble_sort(int *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (arr[j])
		j++;
	while (arr[i])
	{
		while (i < j)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
		i++;
	}
	return (arr);
}

int	*pre_sorting(char **argv, int size)
{
	int		cnt;
	int		*array;
	char	**str;

	array = malloc(sizeof(int) * size);
	cnt = 0;
	while (*argv)
	{
		str = ft_split(*argv, ' ');
		while (*str)
		{
			array[cnt++] = ft_atoi(*str);
			str++;
		}
		argv++;
	}
	return (buble_sort(array));
}
