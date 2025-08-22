/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:12:49 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:41 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	pixel_to_complex(int x, int y, t_fractol *f)
{
	t_complex	c;

	c.re = x / f->zoom + f->offset_x;
	c.im = y / f->zoom + f->offset_y;
	return (c);
}

static int	mandelbrot_iter(t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	if (c.re * c.re + c.im * c.im > 4.0)
		return (0);
	z.re = 0;
	z.im = 0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(x, y, f);
			i = mandelbrot_iter(c);
			*(int *)(f->addr + (y * f->line_len + x * (f->bpp
							/ 8))) = get_color(i, MAX_ITER);
			x++;
		}
		y++;
	}
}
