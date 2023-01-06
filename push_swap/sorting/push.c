/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:43:04 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/06 22:59:40 by gkwon            ###   ########.fr       */
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

t_node	*pop(t_info **info)
{
	t_node	*pop;

	if ((*info)->size < 1)
		return (NULL);
	pop = (*info)->head;
	if ((*info)->size == 1)
	{
		(*info)->head = NULL;
		(*info)->tail = NULL;
	}
	else if ((*info)->size > 1)
	{
		(*info)->head = (*info)->head->next;
		(*info)->head->pre = NULL;
	}
	pop->next = NULL;
	modify_idx(*info, -1);
	(*info)->size--;
	return (pop);
}

void	push(t_info **info, t_node *node)
{
	if ((*info)->size == 0)
	{
		node->idx = 0;
		(*info)->head = node;
		(*info)->tail = node;
	}
	else if ((*info)->size >= 1)
	{
		node->idx = 0;
		modify_idx(*info, 1);
		(*info)->head->pre = node;
		node->next = (*info)->head;
		(*info)->head = node;
	}
	(*info)->size++;
}

void	pa(t_info **info_a, t_info **info_b)
{
	if (!(*info_b)->size)
		return ;
	write(1, "pa\n", 3);
	push(info_a, pop(info_b));
	//pop_push(info_b, info_a);
}

void	pb(t_info **info_a, t_info **info_b)
{
	if (!(*info_a)->size)
		return ;
	write(1, "pb\n", 3);
	push(info_b, pop(info_a));
	//pop_push(info_a, info_b);
}
