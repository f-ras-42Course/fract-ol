/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:56:16 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 18:55:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	if (canvas->fractal_type == JULIA)
		canvas->x_coordinate_zero = -1.5;
	else
		canvas->x_coordinate_zero = -2;
	canvas->y_coordinate_zero = 1.12;
	canvas->x_size = 3;
	canvas->y_size = 2.24;
	canvas->x_increments = canvas->x_size / (WIDTH - 1);
	canvas->y_decrements = canvas->y_size / (HEIGHT - 1);
	canvas->plus_zoom = 0.8888888888888888;
	canvas->minus_zoom = 1.125;
}

void	init_canvas_pip(t_canvas *canvas_pip)
{
	canvas_pip->x_coordinate_zero = -1.5;
	canvas_pip->y_coordinate_zero = 1.12;
	canvas_pip->x_size = 3;
	canvas_pip->y_size = 2.24;
	canvas_pip->x_increments = canvas_pip->x_size / (PIP_WIDTH - 1);
	canvas_pip->y_decrements = canvas_pip->y_size / (PIP_HEIGHT - 1);
	canvas_pip->plus_zoom = 0.8888888888888888;
	canvas_pip->minus_zoom = 1.125;
}
