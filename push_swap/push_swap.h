/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:55:15 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/13 16:55:25 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

long				ft_atoi(const char *str);
void				init_info(t_info **t);
t_node				*init_node(int val, unsigned int idx);
void				init_stack(int argc, int *argv, t_info **info);
int					valid_digit(char **argv, int *size);
int					*parsing(int *array, char **argv, t_info *info_a,
						t_info *info_b);
void				ft_error(void);
int					is_sorted(t_info *info);
int					valid_dup(int *array, long find, int len);
int					get_max_idx(t_info *info_a);
void				modify_idx(t_info *info, int modify);
void				find_pivot_and_pb(int *array, t_info *info_a,
						t_info *info_b);
int					*init_and_redirection(t_info *info_a, t_info *info_b,
						int *array);
void				optimize(t_info *info_a);
void				free_all(t_info **info_a, t_info **info_b);
//	swap
void				sa(int print, t_info *info);
void				sb(int print, t_info *info);
void				ss(int print, t_info *info_a, t_info *info_b);
void				swap(t_info *info);
//	push
void				pa(int print, t_info **info_a, t_info **info_b);
void				pb(int print, t_info **info_a, t_info **info_b);
//	rotate
void				rb(int print, t_info *info);
void				ra(int print, t_info *info);
void				rr(int print, t_info *info_a, t_info *info_b);
void				rotate(t_info *info);
void				modify_idx(t_info *info, int modify);
//	rotate2
void				rra(int print, t_info *info);
void				rrb(int print, t_info *info);
void				rrr(int print, t_info *info_a, t_info *info_b);
void				reverse_rotate(t_info *info);
//	cal
void				cal(t_info *info_a, t_info *info_b);
void				cal2(t_node *tmp_b, int *now, t_info *info_a,
						t_info *info_b);
void				def_sum(int **now);
void				do_op(int *best, t_info *info_a, t_info *info_b);

// sort
void				*hard_coding(t_info *info_a, t_info *info_b);
int					*bubble_sort(int *arr, int size);

#endif