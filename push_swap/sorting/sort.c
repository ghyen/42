/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/30 17:33:13 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_pivot_and_pb(int *array, t_info *info_a, t_info *info_b)
{
	int		p1;
	int		p2;
	int		loop;

	loop = ((info_a->size) / 3 * 2);
	p1 = array[(info_a->size / 3) - 1];
	p2 = array[((info_a->size / 3) * 2) - 1];
	while (loop)
	{
		if (info_a->head->val <= p2)
		{
			pb(&info_a, &info_b);
			if (info_b->head->val <= p1)
				rb(info_b);
			loop--;
		}
		else
			ra(info_a);
	}
	loop = info_a->size;
	while (loop--)
		pb(&info_a, &info_b);
}

int	*bubble_sort(int *arr, int size)
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

int *hard_coding(t_info *info_a, t_info *info_b)
{
	int	min;
	int	idx;
	t_node *tmp;

	while (info_a->size > 3)
	{
		tmp = info_a->head;
		min = INT32_MAX;
		while (tmp)
		{
			if (min > tmp->val)
			{
				min = tmp->val;
				idx = tmp->idx;
			}
			tmp = tmp->next;
		}
		if (idx > info_a->size / 2)
		{
			idx = info_a->size - idx;
			while (idx)
			{
				rra(info_a);
				idx--;
			}
		}
		else
			while (idx)
			{
				ra(info_a);
				idx--;
			}
		pb(&info_a, &info_b);
	}
	if (info_a->head->val > info_a->head->next->val)
		sa(info_a);
	if (info_a->tail->val < info_a->head->val)
		rra(info_a);
	if (info_a->tail->pre->val > info_a->tail->val)
	{
		rra(info_a);
		sa(info_a);
	}
	while (info_b->size)
		pa(&info_a, &info_b);
	return (0);
}

int	*parsing(char **argv, int size, t_info *info_a, t_info *info_b)
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
			if (!valid_dup(array, (long)array[cnt], cnt + 1))
				ft_error();
			str++;
			cnt++;
		}
		argv++;
	}
	init_stack(size, array, &info_a);
	if (info_a->size < 6)
		return (hard_coding(info_a, info_b));
	if (!is_sorted(info_a))
		return (bubble_sort(array, size));
	return (array);
}
