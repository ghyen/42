/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:20:17 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 21:19:21 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drow_window(void *mlx, void *window)
{
	mlx_loop(mlx);
}

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
		ft_init_map(map, fd, cnt + 1);
	map->map_char[cnt] = line;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	int		fd;
	int		cnt;
	t_map	map;

	fd = open("./map/map.ber");
	if (fd <= 0)
		ft_error();
	cnt = 0;
	init_map(&map, fd, cnt);
	mlx = mlx_init();
	if (!mlx)
		return (0);
	window = mlx_new_window(mlx, 1000, 1000, "so_long");
	if (!window)
		return (0);
	mlx_loop(mlx);
}
