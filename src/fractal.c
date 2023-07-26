/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:19:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/25 16:59:49 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_fractal(t_mlx_data *window, t_canvas *canvas)
{
	if(!create_fractal(window, canvas))
		return (false);
	if (!insert_fractal(window))
		return(false);
	return (true);
}

bool	create_fractal(t_mlx_data *window, t_canvas *canvas)
{
	window->background = draw_rectangle(window->mlx, WIDTH, HEIGHT, 0x6432ffff);
	if (!window->background)
		return (false);
	window->image = init_mandelbrot(window->mlx, canvas);
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
