/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:24:28 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/31 20:56:15 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cal(t_info *info_a, t_info *info_b)
{
	t_node	*tmp_b;
	int		best[6];
	int		now[6];
	int		i;

	i = 0;
	while (i < 5)
		best[i++] = 0;
	best[5] = INT_MAX;
	tmp_b = info_b->head;
	while (tmp_b)
	{
		i = -1;
		while (++i < 6)
			now[i] = 0;
		now[5] = INT_MAX;
		cal2(tmp_b, now, info_a, info_b);
		i = -1;
		if (best[5] > now[5])
			while (++i < 6)
				best[i] = now[i];
		tmp_b = tmp_b->next;
	}
	do_op(best, info_a, info_b);
}

int	find_index(t_info *info_a, int val)
{
	t_node	*tmp;
	int		max;
	int		cnt;
	int		max_idx;

	cnt = 0;
	max = INT_MIN;
	tmp = info_a->head;
	while (1)
	{
		if (max < tmp->val)
		{
			max = tmp->val;
			max_idx = cnt;
		}
		if (tmp->next && tmp->val < val && tmp->next->val > val)
			return (cnt + 1);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		cnt++;
	}
	if (tmp->val < val && info_a->head->val > val)
		return (0);
	return (max_idx + 1);
}

void	cal2(t_node *tmp_b, int *now, t_info *info_a, t_info *info_b)
{
	t_node	*tmp_a;
	int		pre;

	pre = INT_MIN;
	tmp_a = info_a->head;
	now[0] = tmp_b->idx;
	if (tmp_b->idx < (unsigned int)(info_b->size / 2))
		now[1] = tmp_b->idx;
	else
		now[2] = info_b->size - tmp_b->idx;
	if (info_a->size > 1)
		now[3] = find_index(info_a, tmp_b->val);
	if (now[3] > 0)
		now[4] = info_a->size - now[3];
	def_sum(&now);
}

void	def_sum(int **now)
{
	int	i;

	i = 0;
	(*now)[5] = 0;
	while (++i < 4)
	{
		if (i == 3)
		{
			if ((*now)[i] != (*now)[i + 1])
			{
				if ((*now)[i] > (*now)[i + 1])
					(*now)[i] = 0;
				else
					(*now)[i + 1] = 0;
			}
			else
				(*now)[i + 1] = 0;
		}
		(*now)[5] += (*now)[i];
	}
}

void	do_op(int *best, t_info *info_a, t_info *info_b)
{
	int	i;

	i = 0;
	while (++i < 5)
	{
		if (i == 3 && best[3] == 0 && best[4] == 0)
			pa(&info_a, &info_b);
		while (best[i] > 0)
		{
			if (i == 1)
				rb(info_b);
			else if (i == 2)
				rrb(info_b);
			else if (i == 3 || i == 4)
			{
				while (i == 3 && best[i]--)
					ra(info_a);
				while (i == 4 && best[i]--)
					rra(info_a);
				pa(&info_a, &info_b);
			}
			best[i]--;
		}
	}
}
