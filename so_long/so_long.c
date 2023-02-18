/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:20:17 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/19 06:09:36 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drow_window(t_map *map)
{
	init_img(map);
	draw_map(map, -1);
	mlx_hook(map->window, X_EVENT_KEY_PRESS, 0, press_key, map);
	mlx_hook(map->window, X_EVENT_KEY_EXIT, 0, exit_game, map);
	mlx_loop(map->mlx);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	init_map(t_map *map, int fd, int cnt)
{
	char	*line;

	line = get_next_line(fd);
	if (cnt == 0)
		map->x = ft_strlen(line) - 1;
	if (!line)
	{
		map->map_char = malloc(sizeof(char *) * (cnt + 1));
		map->y = cnt;
	}
	if (line)
		init_map(map, fd, cnt + 1);
	map->map_char[cnt] = line;
}

void	ft_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(" ERROR\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (!argv || argc == 0)
		return (0);
	map.fd = open("./map/map.ber", O_RDONLY);
	if (map.fd <= 0)
		ft_error(E_FD);
	init_map(&map, map.fd, 0);
	if (!map_valid_check(&map))
		ft_error(E_MAP_BFS);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (0);
	map.window = mlx_new_window(map.mlx, 64 * map.x, 64 * map.y, "so_long");
	if (!map.window)
		return (0);
	drow_window(&map);
}
