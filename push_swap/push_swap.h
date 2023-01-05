/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:55:15 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/05 23:16:03 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
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

static int			long_long_return(int flag);
int					ft_atoi(const char *str);
void				init_info(t_info **t);
t_node				*init_node(int val, unsigned int idx);
void			init_stack(int argc, int *argv, t_info **info);
int					valid_input(char **argv, int *size);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info_a, t_info *info_b);
void				swap(t_info *info);
int					*pre_sorting(char **argv, int size, t_info *info_a);
void				ft_error(void);
int	is_sorted(t_info *info);
#endif
