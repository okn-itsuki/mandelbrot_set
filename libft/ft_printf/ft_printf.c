/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:42:05 by iokuno            #+#    #+#             */
/*   Updated: 2025/05/15 07:07:29 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	fmt_conver(va_list ap, char fmt)
{
	size_t	count;

	count = 0;
	if (fmt == 'c')
		count += my_put_char((char)va_arg(ap, int));
	else if (fmt == 's')
		count += my_put_str(va_arg(ap, char *));
	else if (fmt == '%')
		count += my_put_char('%');
	else if (fmt == 'd' || fmt == 'i')
		count += my_putnbr_dec(va_arg(ap, int), DEC);
	else if (fmt == 'u')
		count += my_putnbr(va_arg(ap, unsigned int), DEC);
	else if (fmt == 'x')
		count += my_putnbr(va_arg(ap, unsigned int), HEX_L);
	else if (fmt == 'X')
		count += my_putnbr(va_arg(ap, unsigned int), HEX_U);
	else if (fmt == 'p')
		count += my_put_ptr((unsigned long)va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	count;
	size_t	i;

	if (!fmt)
		return (-1);
	count = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			count += fmt_conver(ap, fmt[++i]);
			i++;
		}
		else
			count += my_put_char(fmt[i++]);
	}
	va_end(ap);
	return ((int)count);
}
