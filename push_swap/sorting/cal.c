/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:24:28 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/11 00:38:08 by edwin            ###   ########.fr       */
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

void	cal2(t_node *tmp_b, int *now, t_info *info_a, t_info *info_b)
{
	t_node	*tmp_a;
	int		pre;

	pre = INT32_MIN;
	tmp_a = info_a->head;
	now[0] = tmp_b->idx;
	if (tmp_b->idx < (unsigned int)(info_b->size / 2))
		now[1] = tmp_b->idx;
	else
		now[2] = info_b->size - tmp_b->idx;
	while (tmp_a && tmp_b->val > tmp_a->val)
	{
		now[3]++;
		tmp_a = tmp_a->next;
	}
	tmp_a = info_a->tail;
	while (tmp_a && tmp_b->val > tmp_a->val)
	{
		now[4]++;
		tmp_a = tmp_a->pre;
	}
	// while (tmp_a)
	// {
	// 	if (tmp_b->val < tmp_a->val)
	// 	{
	// 		now[3]--;
	// 		if (now[3] < 0)
	// 			now[3] = 0;
	// 		break ;
	// 	}
	// 	else
	// 		now[3]++;
	// 	if (pre > tmp_b->val)
	// 	{
	// 		now[4]--;
	// 		if (now[4] < 0)
	// 			now[4] = 0;
	// 		break ;
	// 	}
	// 	pre = tmp_a->val;
	// 	tmp_a = tmp_a->next;
	// 	if (now[3] == info_a->size)
	// 		now[3] = 0;
	// }
	// tmp_a = info_a->tail;
	// while (tmp_a)
	// {
	// 	if (tmp_b->val > tmp_a->val)
	// 	{
	// 		now[4]--;
	// 		if (now[4] < 0)
	// 			now[4] = 0;
	// 		break ;
	// 	}
	// 	else
	// 		now[4]++;
	// 	if (pre > tmp_b->val)
	// 	{
	// 		now[4]--;
	// 		if (now[4] < 0)
	// 			now[4] = 0;
	// 		break ;
	// 	}
	// 	pre = tmp_a->val;
	// 	tmp_a = tmp_a->pre;
	// 	if (now[4] == info_a->size)
	// 		now[4] = 0;
	// }
	def_sum(&now);
}

void	def_sum(int **now)
{
	int	i;
	int	a;

	i = 0;
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
	int	pa_flag;

	pa_flag = 0;
	i = 0;
	while (++i < 5)
	{
		if (i == 3 && best[i] == 0)
			pa(&info_a, &info_b);
		while (best[i] > 0)
		{
			if (i == 1)
				rb(info_b);
			else if (i == 2)
				rrb(info_b);
			else if (i == 3)
			{
				pa(&info_a, &info_b);
				pa_flag = 1;
				ra(info_a);
			}
			else if (i == 4)
				rra(info_a);
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
	}
	tmp = info_a->tail;
	while (tmp && tmp->pre && tmp->val < tmp->pre->val)
	{
		ra_cnt++;
		tmp = tmp->pre;
	}
	if (ra_cnt > rra_cnt)
		while (rra_cnt--)
			rra(info_a);
	else
		while (ra_cnt--)
			ra(info_a);
}
