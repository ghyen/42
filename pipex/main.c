/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:41:28 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/24 14:53:41 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(char **argv)
{
	while ()
	{
		
	}
}

char	*get_path_envp(char **envp)
{
	char	*path;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path = *envp + 5;
	return (path);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	if (argc < 5)
		return (EXIT_FAILURE);
	path = ft_split(get_path_envp(envp), ':');
	parsing(argv);
	//exec();
}
