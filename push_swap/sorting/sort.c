/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 23:27:20 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
int	*buble_sort(int *arr, int size)
{
	int	i;
	int	tmp;
	int	t_loop;

	t_loop = 0;
	while (t_loop <= size - 1)
	{
		i = 0;
		while (i <= size - t_loop - 2)
		{
			if (arr[i] >= arr[i + 1])
			{
				if (arr[i] == arr[i + 1])
					printf("i is :%d\ni+1 is :%d", arr[i], arr[i + 1]);
					//ft_error();
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		t_loop++;
	}
	return (arr);
}

int	*pre_sorting(char **argv, int size, t_info *info_a)
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
			//printf("%d\n", array[cnt++]);
			str++;
		}
		argv++;
	}
	//int *give = malloc(sizeof(int) * size);
	//ft_memmove(give, array, size);
	init_stack(size, array, &info_a);
	if (!is_sorted(info_a))
		return (buble_sort(array, size));
	else
		return (array);
	return (array);
}
