/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/29 18:23:53 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_info *info)
{
	t_node	*find;
	int		flag;

	flag = 0;
	find = info->head;
	while (find->next)
	{
		if (find->val > find->next->val)
			flag++;
		find = find->next;
	}
	if (flag > 2)
		return (0);
	return (1);
}

void	ft_error(void)
{
	printf("error");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_info	*info_a;
	t_info	*info_b;
	int		*array;

	if (argc == 1)
		exit(0);
	init_info(&info_a);
	init_info(&info_b);
	if (!valid_digit(argv, &info_a->size))
		ft_error();
	array = parsing(++argv, info_a->size, info_a);
	find_pivot_and_pb(array, info_a, info_b);
	//t_node *tmp = info_b->head;
	//while (tmp->next != NULL)
	//{
	//	printf("%d",tmp->val);
	//	tmp = tmp->next;
	//}
	//printf("%d",tmp->val);
	while (info_b->size != 0)
	{
		
		cal(info_a, info_b);
		//if (is_sorted(info_a) == 0)
			//optimize(info_a);
	}
	optimize(info_a);
	// int i = 0;
	// while (i < info_a->size)
	// {
	// 	printf("%d ",array[i++]);
	// }

	//tmp = info_a->head;
	//while (tmp->next != NULL)
	//{
	//	//printf("\n");
	//	printf("%d ",tmp->val);
	//	tmp = tmp->next;
	//}
	//printf("%d",tmp->val);
	return (0);
}
