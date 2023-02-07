/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/07 16:17:07 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	array = malloc(sizeof(int) * info_a->size);
	if (!array)
		return (0);
	if (!parsing(array, argv, info_a, info_b))
		return (0);
	find_pivot_and_pb(array, info_a, info_b);
	while (info_b->size != 0)
		cal(info_a, info_b);
	optimize(info_a);
	free(array);
	free_all(&info_a, &info_b);
	return (0);
}
