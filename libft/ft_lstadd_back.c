/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:53:28 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/20 00:01:03 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
//void	ft_lstadd_back(t_list **lst, t_list *new)
//{
//	t_list *tmp;

//	//printf("\n\n%p\n\n",(*lst));
//	tmp = &(*lst);
//	if (!lst || !new)
//		return ;
//	if (!*lst)
//	{
//		(*lst) = new;
//	}
//	else
//	{
//		*lst = ft_lstlast(*lst);
//		(*lst)->next = new;
//	}
//	new->next = 0;
//	lst = tmp;
//	//printf("\n\nlst%p\n\n",(*lst));
//	//printf("\n\ntmp%p\n\n",(*tmp));
//}
