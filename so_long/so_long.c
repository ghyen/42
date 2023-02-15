/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:20:17 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 23:40:58 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	drow_window(void *mlx, void *window)
//{
//	mlx_loop(mlx);
//}

void	init_map(t_map *map, int fd, int cnt)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		map->map_char = malloc(sizeof(char *) * (cnt + 1));
		map->y = cnt;
	}
	if (line)
		init_map(map, fd, cnt + 1);
	map->map_char[cnt] = line;
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	ft_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("ERROR\n", 2);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_win		win;
	t_map		map;

printf("asdasd: %d",123);
	if (!argv||argc == 0)
		return (0);
	win.fd = open("./map/map.ber", O_RDONLY);
	if (win.fd <= 0)
		ft_error(E_FD);
	printf("asdasd: %d",win.fd);
	init_map(&map, win.fd, 0);
	if (!map_valid_check(&map))
		ft_error(E_MAP_VAL);
	win.mlx = mlx_init();
	if (!win.mlx)
		return (0);

	int i = 0;
	while (map.map_char[i])
	{
		printf("%s\n", map.map_char[i]);
	}
	win.window = mlx_new_window(win.mlx, 1000, 1000, "so_long");
	if (!win.window)
		return (0);
	mlx_loop(win.mlx);
}
