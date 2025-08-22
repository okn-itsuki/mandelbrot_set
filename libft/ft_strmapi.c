/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:16:46 by oitsuki           #+#    #+#             */
/*   Updated: 2025/05/11 21:54:16 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	mem = ft_strdup(s);
	if (mem)
	{
		while (mem[i])
		{
			mem[i] = f(i, mem[i]);
			i++;
		}
	}
	return (mem);
}
