/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:48:55 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/09 14:10:49 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int print, t_info *info)
{
	if (print)
		write(1, "sa\n", 3);
	swap(info);
	return ;
}

void	sb(int print, t_info *info)
{
	if (print)
		write(1, "sb\n", 3);
	swap(info);
}

void	ss(int print, t_info *info_a, t_info *info_b)
{
	if (print)
		write(1, "ss\n", 3);
	swap(info_a);
	swap(info_b);
	return ;
}

void	swap(t_info *info)
{
	int	tmp;

	if (info->size < 2)
		return ;
	tmp = info->head->val;
	info->head->val = info->head->next->val;
	info->head->next->val = tmp;
	return ;
}
