/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:44 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol(const char **av, t_fractol *f)
{
	t_complex	c;

	f->type = (av[1][0] | 0b00100000);
	f->zoom = ZOOM;
	f->offset_x = -((double)WIDTH / 2.0) / f->zoom;
	f->offset_y = -((double)HEIGHT / 2.0) / f->zoom;
	f->mlx = mlx_init();
	if (!f->mlx)
		error_exit("mlx_init failed", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "iokuno");
	if (!f->win)
		error_exit("mlx_new_window failed", f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		error_exit("mlx_new_image failed", f);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	if (!f->addr)
		error_exit("mlx_get_data_addr failed", f);
	arg_check(f, &c, av);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_key_hook(f->win, handle_esc, f);
	mlx_hook(f->win, 17, 0, close_window, f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_loop(f->mlx);
}

int	main(int ac, const char **av)
{
	t_fractol	f;

	ft_memset(&f, 0, sizeof(t_fractol));
	if (invalid_input(ac, av))
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	fractol(av, &f);
	return (EXIT_SUCCESS);
}
