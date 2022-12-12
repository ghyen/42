/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:12 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/12 17:43:13 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (*p || (char)c == 0)
	{
		if (*p == (char)c)
			return ((char *)p);
		p++;
	}
	return (0);
}

char	*ft_free(t_backup *lst, t_backup **head)
{
	t_backup	*tmp;

	tmp = (*head);
	if ((*head)->fd == lst->fd)
	{
		*head = tmp->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
	}
	else
	{
		while (tmp->next && tmp->next != lst)
			tmp = tmp->next;
		if (tmp->next == lst)
		{
			tmp->next = lst->next;
			free(lst->content);
			lst->content = NULL;
			free(lst);
			lst = NULL;
		}
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2, unsigned int s1l,
		unsigned int s2l)
{
	char	*p;
	int		i;

	while (s1[s1l])
		s1l++;
	while (s2[s2l])
		s2l++;
	p = (char *)malloc(s1l + s2l + 1);
	if (!p)
	{
		free((void *)s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	i = -1;
	while (s2[++i])
		p[s1l + i] = s2[i];
	p[s1l + s2l] = 0;
	free((void *)s1);
	return (p);
}

t_backup	*ft_lstnew(int fd)
{
	t_backup	*new_list;

	if (fd > MY_OPEN_MAX)
		return (0);
	new_list = malloc(sizeof(t_backup));
	if (!new_list)
		return (NULL);
	new_list->content = ft_strdup("");
	if (!new_list->content)
	{
		free(new_list);
		return (NULL);
	}
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
