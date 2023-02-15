/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:40:26 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 23:22:41 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	at_least_one(t_map *map, int i, int j)
{
	while (map->map_char[++i])
	{
		while (map->map_char[i][++j])
		{
			if (map->map_char[i][j] == 'C')
				map->collect_cnt++;
			if (map->map_char[i][j] == 'P')
			{
				map->player.x = i;
				map->player.y = j;
				map->player_cnt++;
			}
			if (map->map_char[i][j] == 'E')
				map->exit_cnt++;
		}
	}
	if (map->collect_cnt && map->exit_cnt == 1 && map->player_cnt == 1)
		return (1);
	return (0);
}

int	dfs(t_map *map, t_ui x, t_ui y)
{
	int	i;
	int	j;

	i = -2;
	map->map_visited[y][x] = 1;
	if ((x < 0 || y < 0) || (x > map->x || y > map->y)
		|| map->map_char[y][x] == '1')
		return (0);
	if (map->map_char[y][x] == 'C')
		map->collect_cnt--;
	if (map->map_char[y][x] == 'E')
		return (1);
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			if ((i || j) && (!map->map_visited[y + j][x + i])) // 0,0 제자리 방지
				if (dfs(map, x + i, y + j) == 1)
					return (1);
	}
	return (0);
}

int	valid_exit_check(t_map *map)
{
	int	i;
	unsigned int	j;

	i = -1;
	map->map_visited = malloc(sizeof(int *) * map->y);
	while (map->map_visited[++i])
	{
		j = 0;
		map->map_visited[i] = malloc(sizeof(int) * map->x);
		while (j <= map->x)
			map->map_visited[i][j++] = 0;
	}
	return (dfs(map, map->player.x, map->player.y));
}

int	map_valid_check(t_map *map)
{
	map->collect_cnt = 0;
	map->player_cnt = 0;
	map->exit_cnt = 0;
	if (!at_least_one(map, -1, -1))
		ft_error(E_MAP_VAL);
	if (valid_exit_check(map) && map->collect_cnt == 0)
		return (1);
	return (0);
}
