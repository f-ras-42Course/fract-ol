/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   juliabrot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 15:11:43 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 15:30:04 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_to_julia(t_all *data, float julia[])
{
	julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
	printf("Moved to Julia: %f, %f\n", julia[X], julia[Y]);
	data->canvas.fractal_type = JULIA;
}

void	switch_to_mandelbrot(t_all *data)
{	
	init_canvas(&data->canvas);
	data->canvas.fractal_type = MANDELBROT;
	printf("Changed to Mandelbrot.\n");

}

void	show_julia_coordinates(t_all *data, float julia[])
{
	julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
	printf("Julia coordinates are: %f, %f\n", julia[X], julia[Y]);

}

// void	display_julia_in_pip(t_all *data)
// {

// }

void	julia_coordinates_from_mouse(mlx_t *mlx, t_canvas *canvas)
{
	int32_t	x_mouse_pos;
	int32_t	y_mouse_pos;

	x_mouse_pos = 0;
	y_mouse_pos = 0;
	mlx_get_mouse_pos(mlx, &x_mouse_pos, &y_mouse_pos);
	canvas->julia[X] = \
	canvas->x_coordinate_zero + (canvas->x_increments * x_mouse_pos);
	canvas->julia[Y] = \
	canvas->y_coordinate_zero - (canvas->y_decrements * y_mouse_pos);
}
