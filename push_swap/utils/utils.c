/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:30:10 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/09 14:13:19 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			rra(1, info_a);
			cnt--;
		}
	}
	else
	{
		cnt++;
		while (cnt)
		{
			ra(1, info_a);
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
