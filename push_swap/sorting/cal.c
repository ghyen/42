/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:24:28 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/09 23:41:12 by gkwon            ###   ########.fr       */
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
	while (loop < 6)
	{
		best[loop] = 0;
		now[loop++] = 0;
	}
	best[5] = 9999;
	tmp_b = info_b->head;
	loop = info_b->size;
	while (loop--)
	{
		cal2(tmp_b, now, info_a, info_b);
		//printf("best : %d, now : %d", best[5], now[5]);
		a = best[5];
		b = now[5];
		if (best[5] > now[5])
		{
			i = -1;
			while (++i < 6)
			{
				best[i] = now[i];
			}
		}
		tmp_b = tmp_b->next;
	}
	do_op(best, info_a, info_b);
}

void	cal2(t_node *tmp_b, int *now, t_info *info_a, t_info *info_b)
{
	t_node	*tmp_a;

	tmp_a = info_a->head;
	now[0] = tmp_b->idx;
	if (tmp_b->idx < (info_b->size / 2))
		now[1] = tmp_b->idx;
	else
		now[2] = info_b->size - tmp_b->idx;
	if (info_a->head && info_a->head->val < tmp_b->val)
	{
		while (tmp_b->val > tmp_a->val && tmp_a)
		{
			now[3]++;
			tmp_a = tmp_a->next;
		}
		tmp_a = info_a->tail;
		while (tmp_b->val > tmp_a->val && tmp_a)
		{
			now[4]++;
			tmp_a = tmp_a->pre;
		}
	}
	def_sum(&now);
}

void	def_sum(int **now)
{
	int	i;

	i = 0;
	while (++i < 4)
	{
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
			(*now)[5] += (*now)[i];
		}
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
			else
				rra(info_a);
			best[i]--;
		}
	}
}
