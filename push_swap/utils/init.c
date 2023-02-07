/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/02/07 16:43:40 by gkwon            ###   ########.fr       */
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

int	*init_and_redirection(t_info *info_a, t_info *info_b, int *array)
{
	init_stack(info_a->size, array, &info_a);
	if (is_sorted(info_a))
		exit(0);
	if (info_a->size < 6)
		return (hard_coding(info_a, info_b));
	else
		return (bubble_sort(array, info_a->size));
}

int	*parsing(int *array, char **argv, t_info *info_a, t_info *info_b)
{
	int		cnt;
	char	**str;
	int		i;
	long	tmp;

	cnt = 0;
	while (*(++argv))
	{
		i = -1;
		str = ft_split(*argv, ' ');
		while (str[++i])
		{
			tmp = ft_atoi(str[i]);
			if (!valid_dup(array, tmp, cnt + 1))
				ft_error();
			else
				array[cnt++] = tmp;
			free(str[i]);
		}
		free(str);
	}
	return (init_and_redirection(info_a, info_b, array));
}
