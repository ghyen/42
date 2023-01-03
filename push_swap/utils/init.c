/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/01/04 04:58:47 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *t)
{
	t = (t_info *)malloc(sizeof(t_info));
	t->head_a = NULL;
	t->head_b = NULL;
	t->tail_a = NULL;
	t->tail_b = NULL;
	t->size = 0;
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

void	init_stack(char **argv, t_info *info)
{
	int	idx;

	idx = 0;
	while (**argv)
	{
		init_elm(ft_atoi(*argv, info), info, (&idx)++);
		*argv++;
	}
	
}

void	init_elm(int val, t_info *info, int *idx)
{
	t_node	*pre_node;
	t_node	*cur_node;

	cur_node = init_node(val, *idx++);
	if (!pre_node)
		info->head_a = cur_node;
	else
	{
		pre_node->next = cur_node;
		cur_node->next = pre_node;
	}
	pre_node = cur_node;
}