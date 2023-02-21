/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:26:12 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/21 12:43:37 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define E_MAP_VAL "MAP ELEMENT IS NOT SUPOSSED TO BE"
# define E_FD "MAP OEPN FAILED"
# define PARSINGERR "PARSING FAILED"
# define E_MAP_BFS "MAP CAN NOT SOLVED"
# define E_MAP_N_SQUARE "MAP IS NOT SQUARE"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_player	t_player;
typedef unsigned int	t_ui;
typedef struct s_img	t_img;

typedef struct s_player
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		mov_cnt;
}						t_player;

typedef struct s_img
{
	void				*wall;
	void				*chara;
	void				*land;
	void				*exit;
	void				*bab;
}						t_img;

typedef struct s_map
{
	void				*mlx;
	void				*window;
	int					fd;
	unsigned int		x;
	unsigned int		y;
	struct s_player		player;
	char				**map_char;
	int					**map_visited;
	int					collect_cnt;
	int					all_col_cnt;
	int					exit_cnt;
	int					player_cnt;
	int					exist_exit;
	struct s_img		img;
}						t_map;

/* ===============.=============== */

void					draw_map(t_map *map, unsigned int h);
void					init_img(t_map *map);
int						exit_game(t_map *map);
int						press_key(int key_code, t_map *map);
void					next_mom(t_map *map, unsigned int *x, unsigned int *y,
							int key);
void					move(t_map *map, int key);
void					drow_window(t_map *map);
void					init_map(t_map *map, int fd, int cnt);
void					ft_error(char *error_msg);
int						valid_argv(char **argv);
int						at_least_one(t_map *map, int i, int j);
int						dfs(t_map *map, t_ui x, t_ui y);
int						is_map_closed(t_map *map);
int						valid_exit_check(t_map *map);
int						map_valid_check(t_map *map);

/* ===============./get_next_line=============== */

char					*ft_substr(char const *s, unsigned int start,
							size_t len);
t_backup				*find_fd(t_backup **head, int fd);
char					*cut_nl(t_backup *lst, t_backup **head);
char					*ft_read(ssize_t size, t_backup *lst, t_backup **head,
							int fd);
char					*get_next_line(int fd);
char					*ft_strchr(const char *s, int c);
char					*ft_free(t_backup *lst, t_backup **head);
char					*ft_strjoin(char const *s1, char const *s2,
							unsigned int s1l, unsigned int s2l);
t_backup				*ft_lstnew(int fd);
char					*ft_strdup(const char *s1);

/* ===============./libft=============== */

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_itoa(int n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
char					**ft_split(char const *s, char c);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlen(const char *s);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char					*ft_strrchr(const char *s, int c);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);

#endif
