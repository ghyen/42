/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:56:01 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/20 17:46:40 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*result_str;

	i = -1;
	len = ft_strlen(s);
	result_str = malloc(len + 1);
	if (!result_str)
		return (0);
	while (s[++i])
		result_str[i] = f(i, s[i]);
	result_str[i] = 0;
	return (result_str);
}
