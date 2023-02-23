/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:20 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/23 20:38:58 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	unsigned int	idx;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_info
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_info;

/* ===============.=============== */

void				parsing(void);
char				*get_path_envp(char **envp);

/* ===============./ft_printf=============== */

int					format_c(va_list ap);
int					format_s(va_list ap);
int					format_p(va_list ap);
int					format_d(va_list ap);
int					format_u(va_list ap);
int					format_x_lower(va_list ap);
int					format_x_upper(va_list ap);
int					format_ps(void);
int					ft_printf(const char *format, ...);
size_t				ft_to_add(size_t nb);
size_t				ft_to_hex(unsigned int nb, int letter);
char				*ft_unsigned_itoa(unsigned int n);

/* ===============./ft_printf/libft=============== */

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

/* ===============./get_next_line=============== */

char				*ft_gnl_substr(char const *s, unsigned int start,
						size_t len);
t_backup			*find_fd(t_backup **head, int fd);
char				*cut_nl(t_backup *lst, t_backup **head);
char				*ft_read(ssize_t size, t_backup *lst, t_backup **head,
						int fd);
char				*get_next_line(int fd);
char				*ft_gnl_strchr(const char *s, int c);
char				*ft_free(t_backup *lst, t_backup **head);
char				*ft_gnl_strjoin(char const *s1, char const *s2,
						unsigned int s1l, unsigned int s2l);
t_backup			*ft_gnl_lstnew(int fd);
char				*ft_gnl_strdup(const char *s1);

#endif
