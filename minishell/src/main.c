/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:00:27 by gkwon             #+#    #+#             */
/*   Updated: 2023/04/18 03:54:39 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenize(char *line)
{
	char			**nodes;
	t_av_parsing	*tokens;

	nodes = ft_split(line, ' ');
	while (*nodes)
	{
		printf("%s", *nodes);
		nodes++;
	}
	//return (0);
}

void	write_prompt(void)
{
	write(1, "bash-3.2$ ", 10);
}

int	display(char **envp)
{
	char	*line;

	while (1)
	{
		//write_prompt();
		line = readline("bash-3.2$ ");
		tokenize(line);
		//add_history();
		//excute();
	}
}

int	main(int ac, char **av, char **envp)
{
	//if (ac < 2)
	//	exit(0);
	//execve("/bin/bash", NULL, envp);
	display(envp);
	return (0);
}
