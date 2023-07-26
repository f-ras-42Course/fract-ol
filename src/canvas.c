/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:56:16 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 17:56:37 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->x_coordinate_zero = -2;
	canvas->y_coordinate_zero = 1;
	canvas->x_size = 3;
	canvas->y_size = 2;
	canvas->x_increments = (float)canvas->x_size/(WIDTH - 1);
	canvas->y_decrements = (float)canvas->y_size/(HEIGHT - 1);
	canvas->plus_zoom = 1.01;
	canvas->minus_zoom = 0.99;
}
