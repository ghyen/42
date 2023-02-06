/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:57 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/06 19:29:31 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
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

void				ft_error(void);
int					valid_digit(char **argv, int *size);
int					is_sorted(t_info *info);
void				init_info(t_info **t);
int					*parsing(char **argv, int size, t_info *info_a,
						t_info *info_b);
void				ft_error(void);
//	swap
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info_a, t_info *info_b);
void				swap(t_info *info);
//	push
void				pa(t_info **info_a, t_info **info_b);
void				pb(t_info **info_a, t_info **info_b);
//	rotate
void				rb(t_info *info);
void				ra(t_info *info);
void				rr(t_info *info_a, t_info *info_b);
void				rotate(t_info *info);
void				modify_idx(t_info *info, int modify);
//	rotate2
void				rra(t_info *info);
void				rrb(t_info *info);
void				rrr(t_info *info_a, t_info *info_b);
void				reverse_rotate(t_info *info);
// sort
int					*hard_coding(t_info *info_a, t_info *info_b);
int					*bubble_sort(int *arr, int size);

#endif