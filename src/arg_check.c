/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 05:45:59 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:54 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	is_valid_double(const char *arg)
{
	int	dot_count;
	int	digit_count;

	digit_count = 0;
	dot_count = 0;
	if (!arg || !*arg)
		return (false);
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!*arg)
		return (false);
	while (*arg)
	{
		if (*arg == '.')
			dot_count++;
		else if (!ft_isdigit(*arg))
			return (false);
		else if (ft_isdigit(*arg))
			digit_count = 1;
		arg++;
	}
	if (dot_count > 1 || digit_count < 1)
		return (false);
	return (true);
}

bool	invalid_input(int ac, const char **av)
{
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0))
		return (false);
	if ((ac == 2 || ac == 4) && (ft_strcmp(av[1], "julia") == 0))
	{
		if (ac == 2)
			return (false);
		if (is_valid_double(av[2]) && is_valid_double(av[3]))
			return (false);
	}
	return (true);
}

void	print_usage(void)
{
	ft_printf("erorr : plz parameter !\n");
	ft_printf("==========================================================\n\n");
	ft_printf("mandelbrot-> \"mandelbrot\"\n");
	ft_printf("   julia   -> \"julia\" \"<real>\" \"<img>\"\n\n");
	ft_printf("The second third argument is a numeric value of type double.\n\
If no number is entered, \"0.355\" is the default value\n\n");
}

void	arg_check(t_fractol *f, t_complex *c, const char **av)
{
	if (f->type == 'm')
		draw_mandelbrot(f);
	else if (f->type == 'j')
	{
		if (!av[2] || !av[3])
		{
			c->re = INIT_JULIA;
			c->im = INIT_JULIA;
		}
		else
		{
			c->re = ft_atof(av[2]);
			c->im = ft_atof(av[3]);
		}
		f->c = *c;
		draw_julia(f, c);
	}
}
