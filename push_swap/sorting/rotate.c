/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:43:07 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/06 23:14:11 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_info *info)
{
	t_node	*tmp;

	tmp = info->head;
	modify_idx(info, -1);
	info->head->idx = info->size - 1;
	info->head->next->pre = NULL;
	tmp->next = NULL;
	info->tail->next = tmp;
	tmp->pre = info->tail;
	info->tail = tmp;
	tmp->idx = 0;
}

void	modify_idx(t_info *info, int modify)
{
	t_node	*tmp;

	tmp = info->head;
	while (tmp)
	{
		tmp->idx = tmp->idx + modify;
		tmp = tmp->next;
	}
}

void	ra(t_info *info)
{
	if (info->size < 2)
		return ;
	rotate(info);
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	if (info->size < 2)
		return ;
	rotate(info);
	write(1, "rb\n", 3);
}

void	rr(t_info *info_a, t_info *info_b)
{
	if (info_a->size < 2 || info_b->size < 2)
		return ;
	rotate(info_a);
	rotate(info_b);
	write(1, "rr\n", 3);
}
