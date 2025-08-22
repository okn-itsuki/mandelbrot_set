/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:10:21 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/16 12:40:52 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_fractol *f)
{
	if (!f)
		return ;
	if (f->img && f->mlx)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	if (f->mlx)
		free(f->mlx);
}

int	close_window(t_fractol *f)
{
	free_all(f);
	exit(EXIT_SUCCESS);
	return (0);
}

void	error_exit(const char *msg, t_fractol *f)
{
	perror(msg);
	free_all(f);
	exit(EXIT_FAILURE);
}
