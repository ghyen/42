/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:28:16 by edwin             #+#    #+#             */
/*   Updated: 2023/01/02 22:05:52 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *t)
{
	t = (t_info *)malloc(sizeof(t_info));
	t->head_a = NULL;
	t->head_b = NULL;
	t->tail_a = NULL;
	t->tail_b = NULL;
	t->now = 0;
	t->size = 0;
}

void	init_elm(char **argv)
{
	char **input;

	input = ft_split(*argv, ' ');
}