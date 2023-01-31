/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/01/31 14:13:45 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_info(t_info **t)
{
	*t = (t_info *)malloc(sizeof(t_info));
	(*t)->head = NULL;
	(*t)->tail = NULL;
	(*t)->size = 0;
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

void	init_stack(int size, int *array, t_info **info)
{
	t_node	*pre_node;
	t_node	*cur_node;
	int		idx;

	idx = 0;
	while (size--)
	{
		cur_node = init_node(*array, idx++);
		if ((*info)->head == NULL)
			(*info)->head = cur_node;
		else
		{
			pre_node->next = cur_node;
			cur_node->pre = pre_node;
		}
		pre_node = cur_node;
		array++;
	}
	(*info)->tail = pre_node;
}

int	*init_cal(void)
{
	int	*ret;
	int	loop;

	loop = 5;
	ret = malloc(sizeof(int) * 6);
	while (loop--)
		ret[loop] = 0;
	ret[5] = INT32_MAX;
	return (ret);
}

int	*parsing(char **argv, int size, t_info *info_a, t_info *info_b)
{
	int		cnt;
	int		*array;
	char	**str;

	array = malloc(sizeof(int) * size);
	cnt = 0;
	while (*argv)
	{
		str = ft_split(*argv, ' ');
		while (str[cnt])
		{
			array[cnt] = ft_atoi(str[cnt]);
			if (!valid_dup(array, (long)array[cnt], cnt + 1))
			{
				free(str[cnt]);
				ft_error();
			}
			free(str[cnt]);
			cnt++;
		}
		argv++;
		free(str);
	}
	init_stack(size, array, &info_a);
	if (info_a->size < 6)
		return (hard_coding(info_a, info_b));
	if (!is_sorted(info_a))
		return (bubble_sort(array, size));
	return (array);
}
