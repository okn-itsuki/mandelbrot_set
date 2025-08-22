/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:02:53 by oitsuki           #+#    #+#             */
/*   Updated: 2025/05/11 10:16:09 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char const	*s;
	int			direction;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s)
		return (dest);
	direction = 1;
	if (d > s)
	{
		direction = -1;
		d += n - 1;
		s += n - 1;
	}
	while (n > 0)
	{
		*(unsigned char *)d = *(unsigned char *)s;
		d += direction;
		s += direction;
		n--;
	}
	return (dest);
}
