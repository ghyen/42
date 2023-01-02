/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:55:15 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/02 21:48:17 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				*content;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_info
{
	int				now;
	int				size;
	struct s_node	*head_a;
	struct s_node	*tail_a;
	struct s_node	*head_b;
	struct s_node	*tail_b;
}					t_info;

#endif
