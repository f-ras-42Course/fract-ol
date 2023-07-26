/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 19:59:56 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data)
{
	key_hooks(&data->window);
	mlx_close_hook(data->window.mlx, good_bye_X, NULL);
	return (mlx_loop_hook(data->window.mlx, loop_hooks, data));
}

void	loop_hooks(void *param)
{
	t_all		*data;
	data = param;

	image_hooks(&data->window, &data->canvas);
	show_fps();
}

void	key_hooks(t_mlx_data *window)
{
//new function
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
	show_fps();
}

