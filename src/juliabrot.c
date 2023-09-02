/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   juliabrot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 15:11:43 by fras          #+#    #+#                 */
/*   Updated: 2023/09/02 12:39:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_to_julia(t_all *data, double julia[])
{
	julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
	fractal_float_int_printer(STDOUT_FILENO, "Moved to Julia: %f, %f\n", \
		julia[X], julia[Y]);
	data->canvas.x_coordinate_zero = -1.5;
	mlx_delete_image(data->window.mlx, data->window.fractal_pip);
	data->window.fractal_pip = NULL;
	data->canvas.fractal_type = JULIA;
}

void	switch_to_mandelbrot(t_all *data)
{
	data->canvas.fractal_type = MANDELBROT;
	init_canvas(&data->canvas);
	ft_putstr_fd("Moved to Mandelbrot.\n", STDOUT_FILENO);
}

void	init_julia_in_pip(t_all *data, action_t action)
{
	if (action == MLX_PRESS)
	{
		init_canvas_pip(&data->canvas_pip);
		julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
		data->canvas_pip.julia[X] = data->canvas.julia[X];
		data->canvas_pip.julia[Y] = data->canvas.julia[Y];
		if (!init_pip(&data->window, data->canvas_pip, data->color_scheme))
		{
			unexpected_crash(data->window.mlx);
			exit(EXIT_FAILURE);
		}
	}
}

void	refresh_julia_in_pip(t_all *data)
{
	julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
	data->canvas_pip.julia[X] = data->canvas.julia[X];
	data->canvas_pip.julia[Y] = data->canvas.julia[Y];
	draw_pip_fractal(data->window.fractal_pip, data->canvas_pip, \
						data->color_scheme);
}

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
