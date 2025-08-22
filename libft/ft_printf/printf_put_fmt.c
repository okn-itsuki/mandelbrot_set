/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_put_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:21:19 by iokuno            #+#    #+#             */
/*   Updated: 2025/05/15 07:07:31 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	my_putnbr(unsigned long nbr, const char *hex)
{
	size_t	base_len;
	size_t	i;
	size_t	count;

	count = 0;
	base_len = (int)my_strlen(hex);
	if (nbr >= base_len)
		count += my_putnbr(nbr / base_len, hex);
	i = nbr % base_len;
	count += my_put_char(hex[i]);
	return (count);
}

size_t	my_putnbr_dec(int nbr, const char *dec)
{
	long		nb;
	size_t		count;
	const char	sing = '-';

	count = 0;
	nb = (long)nbr;
	if (nb < 0)
	{
		nb = -nb;
		count += my_put_char(sing);
	}
	count += my_putnbr((unsigned long)nb, dec);
	return (count);
}

size_t	my_put_ptr(unsigned long ptr)
{
	if (!ptr)
		return (my_put_str("(nil)"));
	return (my_put_str("0x") + my_putnbr(ptr, HEX_L));
}
