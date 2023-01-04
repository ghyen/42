/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/01/04 21:08:03 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	long_long_return(int flag)
{
	if (flag == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	long long	tmp;
	int			flag;

	ret = 0;
	flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = ret;
		ret *= 10;
		ret += (*str++ - '0');
		if (tmp > ret)
			return (long_long_return(flag));
	}
	return (ret * flag);
}

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

void	init_stack(int argc, char **argv, t_info **info)
{
	t_node	*pre_node;
	t_node	*cur_node;
	int		idx;

	idx = 0;
	while (--argc)
	{
		cur_node = init_node(ft_atoi(*argv), idx++);
		if ((*info)->head == NULL)
			(*info)->head = cur_node;
		else
		{
			pre_node->next = cur_node;
			cur_node->pre = pre_node;
		}
		pre_node = cur_node;
		*argv++;
	}
	(*info)->tail = pre_node;
	(*info)->size = --idx;
}
