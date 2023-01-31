/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/31 20:57:03 by gkwon            ###   ########.fr       */
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

int	find_min(t_info *info_a)
{
	t_node	*tmp;
	int		min;
	int		idx;

	tmp = info_a->head;
	min = INT_MAX;
	while (tmp)
	{
		if (min > tmp->val)
		{
			min = tmp->val;
			idx = tmp->idx;
		}
		tmp = tmp->next;
	}
	return (idx);
}

void	pb_until_asize3(t_info *info_a, t_info *info_b)
{
	int	idx;

	idx = find_min(info_a);
	while (info_a->size > 3)
	{
		idx = find_min(info_a);
		if (idx > info_a->size / 2)
		{
			idx = info_a->size - idx;
			while (--idx > -1)
				rra(info_a);
		}
		else
			while (--idx > -1)
				ra(info_a);
		pb(&info_a, &info_b);
	}
}

int	*hard_coding(t_info *info_a, t_info *info_b)
{
	pb_until_asize3(info_a, info_b);
	if (find_min(info_a) == 1 && info_a->head->val > info_a->tail->val)
		ra(info_a);
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
