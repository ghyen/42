/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:09 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/03 21:11:58 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define OPEN_MAX 256
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>

typedef struct s_backup
{
	char			*content;
	struct s_list	*next;
}					t_backup;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif