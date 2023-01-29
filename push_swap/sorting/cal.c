/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:24:28 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/29 17:59:47 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
void	cal(t_info *info_a, t_info *info_b)
{
	int		loop;
	t_node	*tmp_b;
	int		best[6];
	int		now[6];
	int		i;
	int		a;
	int		b;

	loop = 0;
	while (loop < 5)
		best[loop++] = 0;
	best[5] = INT32_MAX;
	tmp_b = info_b->head;
	loop = info_b->size;
	while (loop--)
	{
		i = -1;
		while (++i < 6)
			now[i] = 0;
		now[5] = INT32_MAX;
		cal2(tmp_b, now, info_a, info_b);
		//printf("best : %d, now : %d", best[5], now[5]);
		a = best[5];
		b = now[5];
		if (best[5] > now[5])
		{
			i = -1;
			while (++i < 6)
				best[i] = now[i];
		}
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
	max = INT32_MIN;
	tmp = info_a->head;
	if (info_a->size < 2)
		return (0);
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

	pre = INT32_MIN;
	tmp_a = info_a->head;
	// 0->index 1->rb 2->rrb 3->ra 4->rra 5->sum
	now[0] = tmp_b->idx;
	if (tmp_b->idx < (unsigned int)(info_b->size / 2))
		now[1] = tmp_b->idx;
	else
		now[2] = info_b->size - tmp_b->idx;
	now[3] = find_index(info_a, tmp_b->val);
	//while (tmp_a && !is_be_sorted(tmp_a, tmp_b->val))
	//{
	//	now[3]++;
	//	tmp_a = tmp_a->next;
	//}
	if (now[3] > 0)
		now[4] = info_a->size - now[3];
	def_sum(&now);
}

void	def_sum(int **now)
{
	int	i;
	int	a;

	i = 0;
	(*now)[5] = 0;
	while (++i < 4)
	{
		a = (*now)[i];
		if (i == 3)
		{
			if ((*now)[i] != (*now)[i + 1])
			{
				if ((*now)[i] > (*now)[i + 1])
				{
					(*now)[5] += (*now)[i + 1];
					(*now)[i] = 0;
				}
				else
				{
					(*now)[5] += (*now)[i];
					(*now)[i + 1] = 0;
				}
			}
			else
			{
				(*now)[5] += (*now)[i];
				(*now)[i + 1] = 0;
			}
		}
		else
			(*now)[5] += (*now)[i];
		a = (*now)[5];
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
			else if (i == 3)
			{
				while (best[i]--)
					ra(info_a);
				pa(&info_a, &info_b);
			}
			else if (i == 4)
			{
				while (best[i]--)
					rra(info_a);
				pa(&info_a, &info_b);
			}
			best[i]--;
		}
	}
}

void	optimize(t_info *info_a)
{
	int		ra_cnt;
	int		rra_cnt;
	t_node	*tmp;

	ra_cnt = 0;
	rra_cnt = 0;
	tmp = info_a->head;
	while (tmp && tmp->next && tmp->val > tmp->next->val)
	{
		ra_cnt++;
		tmp = tmp->next;
		if (ra_cnt == info_a->size)
		{
			ra_cnt = 0;
			break ;
		}
	}
	tmp = info_a->tail;
	while (tmp && tmp->pre && tmp->val < tmp->pre->val)
	{
		rra_cnt++;
		tmp = tmp->pre;
	}
	if (rra_cnt != 0 && ra_cnt > rra_cnt)
		while (rra_cnt-- > 0)
			rra(info_a);
	else
		while (ra_cnt-- > 0)
			ra(info_a);
}
