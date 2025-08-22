/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:53:27 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:46 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia(t_fractol *f, t_complex *c, int h, int w)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = h / f->zoom + f->offset_x;
	z.im = w / f->zoom + f->offset_y;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = tmp;
		i++;
	}
	*(int *)(f->addr + (w * f->line_len + h * (f->bpp / 8))) = get_color(i,
			MAX_ITER);
}

void	draw_julia(t_fractol *f, t_complex *c)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			julia(f, c, h, w);
			w++;
		}
		h++;
	}
}
