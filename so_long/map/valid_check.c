/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:40:26 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 21:11:47 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*at_least_one(t_map *map, int *start, int i, int j)
{
	int	*flags;

	flags = malloc(sizeof(int) * 3);
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (map->map_char[++i])
	{
		while (map->map_char[i][++j])
		{
			if (map->map_char[i][j] == 'C')
				flags[0]++;
			if (map->map_char[i][j] == 'P')
			{
				start[0] = i;
				start[1] = j;
				flags[1]++;
			}
			if (map->map_char[i][j] == 'E')
				flags[2]++;
		}
	}
	if (flags[0] && flags[1] == 1 && flags[2] == 1)
		return (start);
	return (0);
}

int	init_dfs(t_map *map, int x, int y)
{
	int i;
	int j;

	i = -2;
	if (x < 0 || y < 0)
		return (0);
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if (i || j)
				init_dfs(map, x + i, y + j);
		}

	}
}


int	valid_exit_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_check = malloc(sizeof(int *) * map->y);
	while (map->map_check[i])
	{
		j = 0;
		map->map_check[i] = malloc(sizeof(int) * map->x);
		while (j <= map->x)
			map->map_check[i][j++] = 0;
	}
	init_dfs(map, 0, 0);
	return check(배열**);
}

int	map_valid_check(t_map *map)
{
	int	i;
	int	j;
	int	*start;

	i = -1;
	j = -1;
	start = malloc(sizeof(int) * 2);
	start = at_least_one(map, start, i, j);
	if (!start)
		ft_error();
	valid_exit_check(map);
}
