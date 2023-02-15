/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:26:12 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 23:19:55 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"

# define E_MAP_VAL	"MAP VALID"
# define E_FD		"MAP OEPN FAILED"
# define PARSINGERR	"PARSING FAILED"

typedef struct s_player t_player;
typedef unsigned int t_ui;
typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		fd;
}					t_win;

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
}					t_player;

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	struct s_player	player;
	char			**map_char;
	int				**map_visited;
	int				collect_cnt;
	int				exit_cnt;
	int				player_cnt;
}					t_map;

/* ===============.=============== */

//int			drow_window(void *mlx, void *window);
void			init_map(t_map *map, int fd, int cnt);
void			ft_putstr_fd(char *s, int fd);
void			ft_error(char *error_msg);

/* ===============./map=============== */

int				at_least_one(t_map *map, int i, int j);
int				dfs(t_map *map, t_ui x, t_ui y);
int				valid_exit_check(t_map *map);
int				map_valid_check(t_map *map);

#endif
