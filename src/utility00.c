/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 05:29:30 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:37 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// =====ft_strcmp=============================================================

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (1);
	while (s2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// ===ft_atof=================================================================

static int	skip_space_sign(const char *s, int *idx)
{
	int	sign;

	sign = 1;
	while (s[*idx] == ' ' || (s[*idx] >= 9 && s[*idx] <= 13))
		++(*idx);
	if (s[*idx] == '-' || s[*idx] == '+')
	{
		if (s[*idx] == '-')
			sign = -1;
		++(*idx);
	}
	return (sign);
}

static double	parse_int(const char *s, int *idx)
{
	double	val;

	val = 0.0;
	while (s[*idx] >= '0' && s[*idx] <= '9')
	{
		val = val * 10.0 + (s[*idx] - '0');
		++(*idx);
	}
	return (val);
}

static double	parse_frac(const char *s, int *idx)
{
	double	val;
	double	div;

	val = 0.0;
	div = 1.0;
	if (s[*idx] == '.')
	{
		++(*idx);
		while (s[*idx] >= '0' && s[*idx] <= '9')
		{
			val = val * 10.0 + (s[*idx] - '0');
			div *= 10.0;
			++(*idx);
		}
	}
	return (val / div);
}

double	ft_atof(const char *s)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = skip_space_sign(s, &i);
	res = parse_int(s, &i);
	res += parse_frac(s, &i);
	return (res * sign);
}
