/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/31 15:13:28 by gkwon            ###   ########.fr       */
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
			return (0);
		find = find->next;
	}
	return (1);
}

void	ft_error(void)
{
	printf("error");
	exit(1);
}

void	free_all(t_info **info_a, t_info **info_b)
{
	t_node	*loop;
	t_node	*fre;
	int		i;

	i = 0;
	loop = (*info_a)->head;
	free(*info_b);
	while (i < (*info_a)->size)
	{
		fre = loop;
		loop = loop->next;
		free(fre);
		i++;
	}
	free(*info_a);
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
	array = parsing(++argv, info_a->size, info_a, info_b);
	if (!array)
		return (0);
	find_pivot_and_pb(array, info_a, info_b);
	while (info_b->size != 0)
		cal(info_a, info_b);
	optimize(info_a);
	free(array);
	free_all(&info_a, &info_b);
	system("leaks a.out");
}
