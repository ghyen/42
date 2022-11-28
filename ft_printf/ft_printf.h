/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:04:13 by gkwon             #+#    #+#             */
/*   Updated: 2022/11/28 20:49:02 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putnbr_base(int nbr, char *base);
size_t	ft_to_add(size_t nbr);
char	*ft_unsigned_itoa(unsigned int n);
size_t	ft_to_hex(unsigned int nb, int letter);
int		format_c(va_list ap);
int		format_s(va_list ap);
int		format_p(va_list ap);
int		format_d(va_list ap);
int		format_i(va_list ap);
int		format_u(va_list ap);
int		format_x_lower(va_list ap);
int		format_x_upper(va_list ap);
int		format_ps(void);
int		ft_isprint(int c);

#endif