/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:55 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/07 14:26:32 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_string(t_info *info_a, t_info *info_b, char *string)
{
	if (ft_strncmp(string, "ra", 2) == 0)
		ra(info_a);
	else if (ft_strncmp(string, "rb", 2) == 0)
		rb(info_b);
	else if (ft_strncmp(string, "rra", 3) == 0)
		rra(info_a);
	else if (ft_strncmp(string, "rrb", 3) == 0)
		rrb(info_b);
	else if (ft_strncmp(string, "sa", 2) == 0)
		sa(info_a);
	else if (ft_strncmp(string, "sb", 2) == 0)
		sb(info_b);
	else if (ft_strncmp(string, "pa", 2) == 0)
		pa(&info_a, &info_b);
	else if (ft_strncmp(string, "pb", 2) == 0)
		pb(&info_a, &info_b);
	else if (ft_strncmp(string, "rrr", 3) == 0)
		rrr(info_a, info_b);
	else if (ft_strncmp(string, "rr", 2) == 0)
		rr(info_a, info_b);
	else if (ft_strncmp(string, "ss", 2) == 0)
		ss(info_a, info_b);
	else
		return (0);
	return (1);
}