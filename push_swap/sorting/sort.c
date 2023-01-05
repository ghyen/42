/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 23:46:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			if (arr[i] > arr[i + 1])
			{
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
			array[cnt] = ft_atoi(*str);
			if (!valid_dup(array, (long)array[cnt], cnt))
				ft_error();
			str++;
			cnt++;
		}
		argv++;
	}
	init_stack(size, array, &info_a);
	if (!is_sorted(info_a))
		return (buble_sort(array, size));
	else
		return (array);
	return (array);
}
