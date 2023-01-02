/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/02 22:00:59 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main(int argc, char **argv)
{
	t_info	*info;

	if (argc == 1)
		exit(0);
	init_info(info);
	if (!valid_input(++argv))
		exit(0);
	init_elm(argv, info);
	// sort
	sort(info);
	return ;
}
