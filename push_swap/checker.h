/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:57 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/09 14:08:27 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line/get_next_line.h"
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

int					check_string(t_info *info_a, t_info *info_b, char *string);
void				ft_error(void);
int					valid_digit(char **argv, int *size);
int					is_sorted(t_info *info);
void				init_info(t_info **t);
int					*checker_parsing(int *array, char **argv, t_info *info_a);
void				ft_error(void);
int					valid_dup(int *array, long find, int len);
void				init_stack(int size, int *array, t_info **info);
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
// sort
int					*hard_coding(t_info *info_a, t_info *info_b);
int					*bubble_sort(int *arr, int size);

#endif