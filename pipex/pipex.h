/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:20 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/23 14:17:27 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_node
{
	int				val;
	unsigned int	idx;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_info
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_info;

#endif