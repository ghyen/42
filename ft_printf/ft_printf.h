/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:04:13 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/26 17:48:54 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	*ft_print_memory(void *addr, unsigned int size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putnbr_base(int nbr, char *base);
void	ft_dec_to_hex(int nbr);

#endif