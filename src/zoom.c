/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:57:28 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:33 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, int x, int y, double factor)
{
	double	cx;
	double	cy;

	cx = (double)x / f->zoom + f->offset_x;
	cy = (double)y / f->zoom + f->offset_y;
	f->zoom *= factor;
	f->offset_x = cx - (double)x / f->zoom;
	f->offset_y = cy - (double)y / f->zoom;
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_SCROLL_UP)
		zoom(f, x, y, ZOOM_IN_FACTOR);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom(f, x, y, ZOOM_OUT_FACTOR);
	else
		return (0);
	if (f->type == 'm')
		draw_mandelbrot(f);
	else if (f->type == 'j')
		draw_julia(f, &(f->c));
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
