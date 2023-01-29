/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:55:15 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/29 21:08:58 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

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

int					ft_atoi(const char *str);
void				init_info(t_info **t);
t_node				*init_node(int val, unsigned int idx);
void				init_stack(int argc, int *argv, t_info **info);
int					valid_digit(char **argv, int *size);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info_a, t_info *info_b);
void				swap(t_info *info);
int					*parsing(char **argv, int size, t_info *info_a,
						t_info *info_b);
void				ft_error(void);
int					is_sorted(t_info *info);
int					valid_dup(int *array, long find, int len);
void				reverse_rotate(t_info *info);
void				rotate(t_info *info);
void				modify_idx(t_info *info, int modify);
void				find_pivot_and_pb(int *array, t_info *info_a,
						t_info *info_b);
int					*init_cal(void);
//	push
void				pa(t_info **info_a, t_info **info_b);
void				pb(t_info **info_a, t_info **info_b);

//	rotate
void				rb(t_info *info);
void				ra(t_info *info);
void				modify_idx(t_info *info, int modify);
#endif

//	rotate2
void				rra(t_info *info);
void				rrb(t_info *info);
void				rrr(t_info *info_a, t_info *info_b);

//	cal
void				cal(t_info *info_a, t_info *info_b);
void				cal2(t_node *tmp_b, int *now, t_info *info_a,
						t_info *info_b);
void				def_sum(int **now);
void				do_op(int *best, t_info *info_a, t_info *info_b);
void				optimize(t_info *info_a);