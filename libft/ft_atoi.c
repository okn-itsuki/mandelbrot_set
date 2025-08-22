/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:35:58 by oitsuki           #+#    #+#             */
/*   Updated: 2025/07/06 18:28:17 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	return ((c >= (char)9 && c <= (char)13) || c == (char)32);
}

static int	check_long(int sign, long int nb, char next)
{
	if (sign == 1)
	{
		if (LONG_MAX / 10 < nb)
			return (1);
		if (LONG_MAX / 10 == nb && LONG_MAX % 10 <= next - '0')
			return (1);
	}
	if (sign == -1)
	{
		if (LONG_MIN / -10 < nb)
			return (-1);
		if (LONG_MIN / -10 == nb && LONG_MIN % -10 * -1 <= next - '0')
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nb = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			break ;
		if (check_long(sign, nb, *nptr) == 1)
			return ((int)LONG_MAX);
		if (check_long(sign, nb, *nptr) == -1)
			return ((int)LONG_MIN);
		nb = 10 * nb + (long int)(*nptr - '0');
		nptr++;
	}
	return ((int)(nb * sign));
}
