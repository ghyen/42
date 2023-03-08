/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwin <edwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:10:30 by gkwon             #+#    #+#             */
/*   Updated: 2023/03/07 17:58:17 by edwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

/* ===============./ft_printf=============== */

size_t	ft_to_hex(unsigned int nb, int letter);
int		ft_printf(const char *format, ...);
int		format_c(va_list ap);
int		format_s(va_list ap);
int		format_p(va_list ap);
int		format_d(va_list ap);
char	*ft_unsigned_itoa(unsigned int n);
size_t	ft_to_add(size_t nb);
int		format_u(va_list ap);
int		format_x_lower(va_list ap);
int		format_x_upper(va_list ap);
int		format_ps(void);

/* ===============./ft_printf/libft=============== */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(void *content);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strchr(const char *s, int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isascii(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isprint(int c);
void	ft_putendl_fd(char *s, int fd);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
int		ft_toupper(int c);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	*ft_strrchr(const char *s, int c);
int		ft_isalpha(int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
char	*ft_itoa(int n);
int		ft_tolower(int c);

/* ===============./src=============== */

void	send_message(pid_t pid, char *msg);
void	send_message(pid_t pid, char *msg);

#endif
