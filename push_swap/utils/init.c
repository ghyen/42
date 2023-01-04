/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/01/05 02:05:59 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_info(t_info **t)
{
	*t = (t_info *)malloc(sizeof(t_info));
	(*t)->head = NULL;
	(*t)->tail = NULL;
	(*t)->size = 0;
}

t_node	*init_node(int val, unsigned int idx)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->val = val;
	new->idx = idx;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

void	init_stack(int size, int *argv, t_info **info)
{
	t_node	*pre_node;
	t_node	*cur_node;
	int		idx;

	idx = 0;
	while (--size)
	{
		cur_node = init_node(*argv, idx++);
		if ((*info)->head == NULL)
			(*info)->head = cur_node;
		else
		{
			pre_node->next = cur_node;
			cur_node->pre = pre_node;
		}
		pre_node = cur_node;
		(*argv)++;
	}
	(*info)->tail = pre_node;
}
