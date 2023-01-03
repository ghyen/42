/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:49:19 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/04 02:49:47 by edwin            ###   ########.fr       */
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
	init_stack(argv, info);
	// sort
	sort(info);
	return ;
}
