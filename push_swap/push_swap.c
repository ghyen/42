/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/06 19:29:35 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize(t_info *info_a)
{
	int	cnt;

	cnt = 0;
	cnt = get_max_idx(info_a);
	if (cnt > info_a->size / 2)
	{
		cnt = info_a->size - cnt - 1;
		while (cnt)
		{
			rra(info_a);
			cnt--;
		}
	}
	else
	{
		cnt++;
		while (cnt)
		{
			ra(info_a);
			cnt--;
		}
	}
}

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
	write(1, "Error\n", 6);
	exit(1);
}

void	free_all(t_info **info_a, t_info **info_b)
{
	t_node	*loop;
	t_node	*fre;
	int		i;

	i = 0;
	free(*info_b);
	*info_b = NULL;
	loop = (*info_a)->head;
	while (i < (*info_a)->size)
	{
		fre = loop;
		loop = loop->next;
		free(fre);
		fre = NULL;
		i++;
	}
	free(*info_a);
	*info_a = NULL;
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
	array = parsing(argv, info_a->size, info_a, info_b);
	if (!array)
		return (0);
	find_pivot_and_pb(array, info_a, info_b);
	while (info_b->size != 0)
		cal(info_a, info_b);
	optimize(info_a);
	free(array);
	free_all(&info_a, &info_b);
	return (0);
}
