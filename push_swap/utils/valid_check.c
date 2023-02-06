/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:29:32 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/06 12:41:56 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_digit(char **argv, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] != 0 && !ft_isdigit(argv[i][j]))
				return (0);
			if ((*size)++ >= 0 && argv[i][j] == ' ')
				j++;
		}
	}
	return (1);
}

int	valid_dup(int *array, long find, int len)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < len)
	{
		if (find > INT_MAX || find < INT_MIN)
			return (0);
		if (array[i++] == find)
		{
			cnt++;
			if (cnt > 1)
				return (0);
		}
	}
	return (1);
}

int	get_max_idx(t_info *info_a)
{
	int		i;
	int		idx;
	int		max;
	t_node	*tmp;

	tmp = info_a->head;
	max = INT_MIN;
	i = 0;
	idx = 0;
	while (i < info_a->size)
	{
		if (max < tmp->val)
		{
			max = tmp->val;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (idx);
}
