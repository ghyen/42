/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/04 23:11:48 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (len == 0 || *s == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) <= len + start)
		len = ft_strlen(s) - start;
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

char	*cut_nl(t_backup *lst, char *buff)
{
	int		at;
	char	*tmp;

	at = 0;
	while (buff[at] && buff[at] != '\n')
		at++;
	tmp = ft_strjoin(lst->content, ft_substr(buff, 0, at));
	free(lst->content);
	lst->content = ft_strdup(ft_substr(buff, at, ft_strlen(buff)));
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_backup	*head;
	char			buff[BUFF_SIZE + 1];
	t_backup		*lst;
	int				size;

	lst = find_fd(head, fd);
	if (!head)
		head = lst;
	while (1)
	{
		size = read(fd, buff, BUFF_SIZE);
		if (size < 1)
		{
			break ;
		}
		if ((ft_strchr(lst->content, '\n')))
		{
			break ;
		}
		buff[size] = 0;
		lst->content = ft_strjoin(lst->content, buff);
	}
	return (cut_nl(lst, buff));
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	//printf("%s", get_next_line(0));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
}
