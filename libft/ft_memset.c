/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:21 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/09 16:12:04 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *p;

    p = b;
    while (len)
    {
        *p++ = (unsigned char)c;
        len--;
    }
    return (b);
}