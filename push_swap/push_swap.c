/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 02:11:46 by gkwon            ###   ########.fr       */
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

void	ft_error()
{
	printf("error");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_info	*info_a;
	t_info	*info_b;
	int *array;

	if (argc == 1)
		exit(0);
	init_info(&info_a);
	init_info(&info_b);
	if (!valid_input(++argv, &info_a->size))
		ft_error();
	array = pre_sorting(argv, info_a->size);
	init_stack(info_a->size, array, &info_a);
	printf("%d",info_a->size);
	//pre-sorting
	//indexing and find pivot
	//pb
	//find cost
	//lowest cost first pa
	//optimize
	//sort(info);
	return (0);
}
