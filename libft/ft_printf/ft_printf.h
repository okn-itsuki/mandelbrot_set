/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:37:01 by iokuno            #+#    #+#             */
/*   Updated: 2025/05/15 06:46:25 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"

size_t	my_strlen(const char *str);
ssize_t	my_put_char(const char c);
ssize_t	my_put_str(const char *s);

size_t	my_putnbr(unsigned long nbr, const char *hux);
size_t	my_putnbr_dec(int nbr, const char *dec);
size_t	my_put_ptr(unsigned long nbr);

int		ft_printf(const char *fmt, ...);

#endif
