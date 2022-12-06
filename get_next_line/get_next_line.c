/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/06 18:30:29 by gkwon            ###   ########.fr       */
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

char	*cut_nl(t_backup *lst, int flag)
{
	int		at;
	char	*tmp;
	char	*fre;

	at = 0;
	while (lst->content[at] && lst->content[at] != '\n')
		at++;
	fre = lst->content;
	tmp = ft_substr(lst->content, 0, at + flag);
	lst->content = ft_strdup(lst->content + at + flag);
	free(fre);
	fre = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_backup	*head;
	char			buff[BUFF_SIZE + 1];
	t_backup		*lst;
	int				size;
	int				flag;

	flag = 0;
	lst = find_fd(head, fd);
	if (!head)
		head = lst;
	while (1)
	{
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = 0;
		lst->content = ft_strjoin(lst->content, buff);
		if (size < 1)
		{
			break ;
			//free node
		}
		if ((ft_strchr(lst->content, '\n')))
		{
			flag = 1;
			break ;
		}
	}
	return (cut_nl(lst, flag));
}

//#include <fcntl.h>
//#include <stdio.h>
//int	main(void)
//{
//	int	fd;

//	fd = open("./test.txt", O_RDONLY);
//	//printf("%s", get_next_line(0));
//	//printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	close(fd);
//}
