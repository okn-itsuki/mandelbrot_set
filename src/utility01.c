/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:42:21 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:35 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = (int)(100 * t);
	b = (int)(50 * (1 - t));
	return (r << 16 | g << 8 | b);
}

int	handle_esc(int keycode, t_fractol *f)
{
	if (keycode == ESC_KEY)
		return (close_window(f));
	return (0);
}
