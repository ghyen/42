/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:26:12 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/19 06:12:00 by gkwon            ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2


typedef struct s_player	t_player;
typedef unsigned int	t_ui;
typedef struct s_img	t_img;

//typedef struct s_win
//{
//	void				*mlx;
//	void				*window;
//	int					fd;
//}						t_win;

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

void			draw_map(t_map *map, unsigned int h);
void			init_img(t_map *map);
int				exit_game(t_map *map);
int				press_key(int key_code, t_map *map);
void			next_mom(t_map *map, unsigned int *x, unsigned int *y, int key);
void			move(t_map *map, int key);
void			drow_window(t_map *map);
size_t			ft_strlen(const char *s);
void			init_map(t_map *map, int fd, int cnt);
void			ft_putstr_fd(char *s, int fd);
void			ft_error(char *error_msg);
void			ft_putnbr_fd(unsigned int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				at_least_one(t_map *map, int i, int j);
int				dfs(t_map *map, t_ui x, t_ui y);
int				valid_exit_check(t_map *map);
int				map_valid_check(t_map *map);

/* ===============./get_next_line=============== */

char			*ft_substr(char const *s, unsigned int start, size_t len);
t_backup		*find_fd(t_backup **head, int fd);
char			*cut_nl(t_backup *lst, t_backup **head);
char			*ft_read(ssize_t size, t_backup *lst, t_backup **head, int fd);
char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_free(t_backup *lst, t_backup **head);
char			*ft_strjoin(char const *s1, char const *s2, unsigned int s1l,
				unsigned int s2l);
t_backup		*ft_lstnew(int fd);
char			*ft_strdup(const char *s1);

#endif
