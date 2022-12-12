/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:09 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/12 17:43:06 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MY_OPEN_MAX 49152
# include <stdlib.h>
# include <unistd.h>

typedef struct s_backup
{
	int				fd;
	char			*content;
	struct s_backup	*next;
}					t_backup;

char				*get_next_line(int fd);
t_backup			*find_fd(t_backup **head, int fd);
char				*ft_read(ssize_t size, t_backup *lst, t_backup **head,
						int fd);
char				*cut_nl(t_backup *lst, t_backup **head);

char				*ft_strjoin(char const *s1, char const *s2,
						unsigned int s1l, unsigned int s2l);
t_backup			*ft_lstnew(int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_free(t_backup *lst, t_backup **head);

#endif
