/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:55 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 16:49:23 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_string(t_info *info_a, t_info *info_b, char *string)
{
	if (ft_strncmp(string, "ra\n", 3) == 0)
		ra(0, info_a);
	else if (ft_strncmp(string, "rb\n", 3) == 0)
		rb(0, info_b);
	else if (ft_strncmp(string, "rra\n", 4) == 0)
		rra(0, info_a);
	else if (ft_strncmp(string, "rrb\n", 4) == 0)
		rrb(0, info_b);
	else if (ft_strncmp(string, "sa\n", 3) == 0)
		sa(0, info_a);
	else if (ft_strncmp(string, "sb\n", 3) == 0)
		sb(0, info_b);
	else if (ft_strncmp(string, "pa\n", 3) == 0)
		pa(0, &info_a, &info_b);
	else if (ft_strncmp(string, "pb\n", 3) == 0)
		pb(0, &info_a, &info_b);
	else if (ft_strncmp(string, "rrr\n", 4) == 0)
		rrr(0, info_a, info_b);
	else if (ft_strncmp(string, "rr\n", 3) == 0)
		rr(0, info_a, info_b);
	else if (ft_strncmp(string, "ss\n", 3) == 0)
		ss(0, info_a, info_b);
	else
		return (0);
	return (1);
}

int	*checker_parsing(int *array, char **argv, t_info *info_a)
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
			if (!valid_dup(array, tmp, cnt))
				ft_error();
			else
				array[cnt++] = tmp;
			free(str[i]);
		}
		free(str);
	}
	init_stack(info_a->size, array, &info_a);
	return (0);
}
