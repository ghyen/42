/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/01 22:11:34 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**backup;
	char		*buff;
	int			i;

	backup = (char **)malloc(sizeof(char *) * OPEN_MAX);
	buff = malloc(BUFF_SIZE + 1);
	buff[BUFF_SIZE] = 0;
	while (1)
	{
		i = -1;
		if (read(fd, buff, BUFF_SIZE) < 1)
		{
			free(buff);
			return (*backup);
		}
		if (is_in_nl(buff) != -1)
		{
			ft_memcpy(*backup, buff, is_in_nl(buff));
			return (*backup++);
		}
		*backup = ft_strjoin(*backup, buff);
	}
	return (*backup++);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	//printf("%s", get_next_line(0));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
}
