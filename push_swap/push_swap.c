/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/04 22:03:34 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_info *info)
{
	while (info->head->next)
	{
		if (info->head->val > info->head->next->val)
			return (0);
		info->head = info->head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info_a;
	t_info	*info_b;

	if (argc == 1)
		exit(0);
	init_info(&info_a);
	init_info(&info_b);
	if (!valid_input(++argv))
		exit(0);
	init_stack(argc, argv, &info_a);
	//pre-sorting
	//indexing and find pivot
	//pb
	//find cost
	//lowest cost first pa
	//optimize
	//sort(info);
	return (0);
}
