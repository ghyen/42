/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:02 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/30 23:35:21 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	int			i;

	buff = malloc(BUFF_SIZE + 1);
	buff[BUFF_SIZE] = 0;
	while (1)
	{
		i = -1;
		if (read(fd, buff, BUFF_SIZE) < 1)
		{
			free(buff);
			return (NULL);
		}
		backup = buff;
		while (backup[++i])
			if (backup[i] == '\n')
				break;
	}
	return (buff);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("./test.txt", O_RDONLY);
	printf("%s", get_next_line(0));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	close(fd);
}
