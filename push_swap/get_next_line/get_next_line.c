/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/07 13:28:10 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	slen;
	int				i;

	i = -1;
	slen = 0;
	while (s[slen])
		slen++;
	if (len == 0 || *s == 0 || slen <= start)
		return (ft_strdup(""));
	if (slen <= len + start)
		len = slen - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	while (start < len)
		ret[++i] = s[start++];
	ret[len] = '\0';
	return (ret);
}

t_backup	*find_fd(t_backup **head, int fd)
{
	t_backup	*at;

	at = *head;
	if (!*head)
	{
		*head = ft_lstnew_gnl(fd);
		if (!*head)
			return (0);
		return (*head);
	}
	while (at)
	{
		if (fd == at->fd)
			break ;
		if (!at->next)
		{
			at->next = ft_lstnew_gnl(fd);
			if (!at->next)
				return (0);
		}	
		at = at->next;
	}
	return (at);
}

char	*cut_nl(t_backup *lst, t_backup **head)
{
	int		at;
	char	*tmp;
	char	*fre;

	at = 0;
	while (lst->content[at] && (lst->content[at] != '\n'))
		at++;
	tmp = ft_substr(lst->content, 0, at + 1);
	if (!tmp)
		return (ft_free(lst, head));
	if (!lst->content[at + 1])
		ft_free(lst, head);
	else
	{
		fre = lst->content;
		lst->content = ft_strdup(lst->content + at + 1);
		free(fre);
		if (!lst->content)
		{
			free(tmp);
			return (ft_free(lst, head));
		}
	}
	return (tmp);
}

char	*ft_read(ssize_t size, t_backup *lst, t_backup **head, int fd)
{
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	while (!(ft_strchr(lst->content, '\n')) && size)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (ft_free(lst, head));
		buff[size] = 0;
		lst->content = ft_strjoin_gnl(lst->content, buff, 0, 0);
		if (!lst->content)
			return (ft_free(lst, head));
		if (lst->content[0] == 0)
			return (ft_free(lst, head));
	}
	if (ft_strchr(lst->content, '\n'))
		return (cut_nl(lst, head));
	tmp = ft_strdup(lst->content);
	if (!tmp)
		return (ft_free(lst, head));
	ft_free(lst, head);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_backup	*head;
	t_backup		*lst;
	ssize_t			size;

	if (BUFFER_SIZE < 1)
		return (0);
	size = 1;
	lst = find_fd(&head, fd);
	if (!lst)
		return (NULL);
	return (ft_read(size, lst, &head, fd));
}
