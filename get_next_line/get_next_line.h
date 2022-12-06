/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:09 by gkwon             #+#    #+#             */
/*   Updated: 2022/12/07 04:44:37 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>

typedef struct s_backup
{
	char			*content;
	struct s_backup	*next;
	int				fd;
}					t_backup;

char				*get_next_line(int fd);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
t_backup			*ft_lstnew(int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
t_backup			*find_fd(t_backup *head, int fd);
char				*cut_nl(t_backup *lst, t_backup *head, int size);
char				*ft_strdup(const char *s1);
void				ft_free(t_backup *lst, t_backup *head);

#endif