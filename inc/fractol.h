/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:32:16 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// my library
# include "ft_printf.h"
# include "libft.h"

// minilibx
# include "mlx.h"

// macro
# include "macro.h"

// stdheder
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// struct
typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		zoom;
	double		offset_x;
	double		offset_y;
	char		type;
	t_complex	c;
}				t_fractol;

// arg_cheak.c
int				handle_esc(int keycode, t_fractol *f);
bool			invalid_input(int ac, const char **av);
void			print_usage(void);
void			arg_check(t_fractol *f, t_complex *c, const char **av);

// utility.c
int				get_color(int iter, int max_iter);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atof(const char *s);

// error.c
void			free_all(t_fractol *f);
int				close_window(t_fractol *f);
void			error_exit(const char *msg, t_fractol *f);

// julia.c
void			draw_julia(t_fractol *f, t_complex *c);

// mandelbrot.c
void			draw_mandelbrot(t_fractol *f);

// zoom.c
int				mouse_hook(int button, int x, int y, t_fractol *f);

#endif
