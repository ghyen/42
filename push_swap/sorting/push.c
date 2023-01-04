/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:43:04 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 01:10:31 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop_push(t_info **from_info, t_info **to_info)
{
	if (!(*from_info)->size)
		return ;
	if ((*to_info)->size == 0)
		(*to_info)->head = (*from_info)->head;
	else if ((*from_info)->size == 1)
	{
		(*to_info)->head->pre = (*from_info)->head;
		(*from_info)->head->next = (*to_info)->head;
		(*to_info)->head = (*from_info)->head;
		(*from_info)->head = NULL;
	}
	else
	{
		(*from_info)->head->next->pre = NULL;
		(*to_info)->head->pre = (*from_info)->head;
		(*from_info)->head = (*from_info)->head->next;
		(*to_info)->head->pre->next = (*to_info)->head;
		(*to_info)->head = (*to_info)->head->pre;
	}
	(*from_info)->size--;
	(*to_info)->size++;
}

void	pa(t_info **info_a, t_info **info_b)
{
	if (!(*info_b)->size)
		return ;
	write(1, "pa\n", 3);
	pop_push(info_b, info_a);
}

void	pb(t_info **info_a, t_info **info_b)
{
	if (!(*info_a)->size)
		return ;
	write(1, "pb\n", 3);
	pop_push(info_a, info_b);
}
