/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_put_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:42:01 by iokuno            #+#    #+#             */
/*   Updated: 2025/05/15 07:07:30 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	my_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (my_put_str("(null)"));
	len = 0;
	while (str[len])
		len++;
	return (len);
}

ssize_t	my_put_char(const char c)
{
	return (write(1, &c, 1));
}

ssize_t	my_put_str(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, my_strlen(s)));
}
