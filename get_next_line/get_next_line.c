/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/07 04:46:07 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	slen;

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
	ft_memmove(ret, s + start, len);
	ret[len] = '\0';
	return (ret);
}

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

t_backup	*find_fd(t_backup *head, int fd)
{
	t_backup	*at;

	at = head;
	if (!at)
	{
		at = ft_lstnew(fd);
		if (!at)
			return (0);
	}
	while (at)
	{
		if (fd == at->fd)
			break ;
		if (!at->next)
			at->next = ft_lstnew(fd);
		at = at->next;
	}
	return (at);
}

char	*cut_nl(t_backup *lst, t_backup **head, int size)
{
	int		at;
	char	*tmp;

	at = 0;
	if (size == -1)
	{
		ft_free(lst, head);
		return (0);
	}
	while (lst->content[at] && lst->content[at] != '\n')
		at++;
	if (at == 0)
	{
		ft_free(lst, head);
		return (0);
	}
	tmp = ft_substr(lst->content, 0, at + 1);
	if (lst->content[at] != '\n')
		ft_free(lst, head);
	else
		lst->content = ft_strdup(lst->content + at + 1);
	return (tmp);
}

int		eof(int size, t_backup *lst, t_backup **head)
{
	char *tmp;

	tmp = ft_strdup(lst->content);
	ft_free(lst, head);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_backup	*head;
	char			buff[BUFFER_SIZE + 1];
	t_backup		*lst;
	ssize_t			size;

	if (BUFFER_SIZE < 1)
		return (0);
	size = 1;
	lst = find_fd(head, fd);
	if (!head)
		head = lst;
	while (!(ft_strchr(lst->content, '\n')) && size)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 1)
			eof(size, lst, head);
		buff[BUFFER_SIZE] = 0;
		lst->content = ft_strjoin(lst->content, buff);
		if (lst->content[0] == 0)
		{
			ft_free(lst, &head);
			return (0);
		}
	}
	return (cut_nl(lst, &head, size));
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;

// 	fd = open("./a.txt", O_RDONLY);
// 	//printf("%s", get_next_line(0));
// 	//printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// }
