/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:26:12 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/15 20:55:55 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "./minilibx/mlx.h"
# include "./get_next_line.h"

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	struct s_player	*player;
	char			**map_char;
	int				**map_check;
}					t_map;

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	struct s_node	*head;
	struct s_node	*tail;
}					t_player;

#endif