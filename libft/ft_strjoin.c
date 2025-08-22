/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:16:29 by okunoitsuki       #+#    #+#             */
/*   Updated: 2025/05/11 21:53:40 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	total_len;

	if (!s1 || !s2)
		return (ft_strdup(""));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mem = (char *)malloc(total_len * sizeof(char));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, total_len);
	ft_strlcat(mem, s2, total_len);
	return (mem);
}
