/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:55:15 by gkwon             #+#    #+#             */
/*   Updated: 2023/01/06 22:40:10 by gkwon            ###   ########.fr       */
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
void				init_stack(int argc, int *argv, t_info **info);
int					valid_digit(char **argv, int *size);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info_a, t_info *info_b);
void				swap(t_info *info);
int					*parsing(char **argv, int size, t_info *info_a);
void				ft_error(void);
int					is_sorted(t_info *info);
int					valid_dup(int *array, long find, int len);
void				reverse_rotate(t_info *info);
void				rotate(t_info *info);
void				modify_idx(t_info *info, int modify);
void	find_pivot_and_pb(int *array, t_info *info_a, t_info *info_b);
//	push
void	pa(t_info **info_a, t_info **info_b);
void	pb(t_info **info_a, t_info **info_b);

//	rotate
void	rb(t_info *info);
void	modify_idx(t_info *info, int modify);
#endif
