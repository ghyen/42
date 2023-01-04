/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:48:55 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/04 22:07:16 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_info *info)
{
	write(1, "sa\n", 3);
	swap(info);
	return ;
}

void	sb(t_info *info)
{
	write(1, "sb\n", 3);
	swap(info);
}

void	ss(t_info *info_a, t_info *info_b)
{
	write(1, "ss\n", 3);
	swap(info_a);
	swap(info_b);
	return ;
}

void	swap(t_info *info)
{
	int	tmp;

	if (info->size < 2)
		return (0);
	tmp = info->head->val;
	info->head->val = info->head->next->val;
	info->head->next->val = tmp;
	return ;
}
