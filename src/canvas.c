/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:56:16 by fras          #+#    #+#                 */
/*   Updated: 2023/08/18 15:11:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->x_coordinate_zero = -2;
	canvas->y_coordinate_zero = 1;
	canvas->x_size = 3;
	canvas->y_size = 2;
	canvas->x_increments = canvas->x_size/(WIDTH - 1);
	canvas->y_decrements = canvas->y_size/(HEIGHT - 1);
	canvas->plus_zoom = 0.8888888888888888;
	canvas->minus_zoom = 1.125;
}
