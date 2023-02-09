/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:43:04 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/09 14:10:01 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	pa(int print, t_info **info_a, t_info **info_b)
{
	if (!(*info_b)->size)
		return ;
	if (print)
		write(1, "pa\n", 3);
	push(info_a, pop(info_b));
}

void	pb(int print, t_info **info_a, t_info **info_b)
{
	if (!(*info_a)->size)
		return ;
	if (print)
		write(1, "pb\n", 3);
	push(info_b, pop(info_a));
}
