/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:19:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/23 15:44:25 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_fractal(t_mlx_data *window, t_canvas *canvas, uint32_t color_scheme[])
{
	if(!create_fractal(window, canvas, color_scheme))
		return (false);
	if (!insert_fractal(window))
		return(false);
	return (true);
}

bool	create_fractal(t_mlx_data *window, t_canvas *canvas,  uint32_t color_scheme[])
{
	window->background = draw_rectangle(window->mlx, WIDTH, HEIGHT, 0x6432ffff);
	if (!window->background)
		return (false);
	window->image = init_mandelbrot(window->mlx, canvas, color_scheme);
	if (!window->image)
		return (false);
	return (true);
}

bool	insert_fractal(t_mlx_data *window)
{
	if (mlx_image_to_window(window->mlx, window->background, 0, 0) == -1)
		return (false);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		return (false);
	return (true);
}
