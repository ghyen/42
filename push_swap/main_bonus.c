/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:25:45 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/07 14:26:11 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_info	*info_a;
	t_info	*info_b;
	char	*tmp;

	if (argc == 1)
		exit(0);
	init_info(&info_a);
	init_info(&info_b);
	if (!valid_digit(argv, &info_a->size))
		ft_error();
	parsing(argv, info_a->size, info_a, info_b);
	tmp = get_next_line(0);
	if (check_string(info_a, info_b, tmp) == 0)
		ft_error();
	if (info_b->size == 0 && is_sorted(info_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
