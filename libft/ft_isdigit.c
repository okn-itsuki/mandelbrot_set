/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:36:31 by oitsuki           #+#    #+#             */
/*   Updated: 2025/07/07 21:50:36 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// A function that checks whether the given character is a digit '0' ~ '9'.

int	ft_isdigit(int c)
{
	return (0x30 <= c && c <= 0x39);
}
