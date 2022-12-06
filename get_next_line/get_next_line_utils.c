/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:12 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/07 04:40:51 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(t_backup *lst, t_backup *head)
{
	while (head->next && !(head->next == lst))
		head = head->next;
	head->next = lst->next;
	free(lst->content);
	lst->content = NULL;
	free(lst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*soruce;

	dest = dst;
	soruce = (unsigned char *)src;
	if (dest == soruce || len == 0)
		return (dest);
	if (dest > soruce && len)
	{
		dest += len - 1;
		soruce += len - 1;
		while (len--)
			*dest-- = *soruce--;
	}
	if (dest < soruce && len)
		while (len--)
			*dest++ = *soruce++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	s1l;
	unsigned int	s2l;

	s1l = 0;
	s2l = 0;
	while (s1[s1l])
		s1l++;
	while (s2[s2l])
		s2l++;
	p = (char *)malloc(s1l + s2l + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, s1l);
	ft_memmove(p + s1l, s2, s2l);
	p[s1l + s2l] = 0;
	free((void *)s1);
	return (p);
}

t_backup	*ft_lstnew(int fd)
{
	t_backup	*new_list;

	new_list = malloc(sizeof(t_backup));
	if (!new_list)
		return (NULL);
	new_list->content = ft_strdup("");
	new_list->next = NULL;
	new_list->fd = fd;
	return (new_list);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;

	len = 0;
	while (s1[len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (*s1)
		*ret++ = (char)*s1++;
	*ret = 0;
	return (ret - len);
}
