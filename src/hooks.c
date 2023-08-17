/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/08/17 16:14:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->window.mlx, key_hooks, data);
	mlx_close_hook(data->window.mlx, good_bye_X, NULL);
	return (mlx_loop_hook(data->window.mlx, loop_hooks, data));
}

void	loop_hooks(void *param)
{
	t_all *data;

	data = param;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE)\
		|| mlx_is_key_down(data->window.mlx, MLX_KEY_Q))
		mlx_close_window(data->window.mlx);
	image_hooks(&data->window, &data->canvas);
	show_fps(0);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_all		*data;
	t_canvas	*canvas;
	
	data = param;
	canvas = &data->canvas;
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS))
		mlx_close_window(data->window.mlx);
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		canvas->y_coordinate_zero += (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		canvas->x_coordinate_zero -= (WIDTH * 0.125) * canvas->x_increments;
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)\
		|| (keydata.key ==MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		canvas->y_coordinate_zero -= (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)\
	|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		canvas->x_coordinate_zero += (WIDTH * 0.125) * canvas->x_increments;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		show_fps(true);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		show_canvas_data(*canvas);
	image_zoom(keydata, canvas);
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
}

void	image_zoom(mlx_key_data_t keydata, t_canvas *canvas)
{
	double	x_midscreen_canvas_value;
	double	x_midscreen_canvas_value;
	
	x_midscreen_canvas_value = canvas->x_coordinate_zero + ((WIDTH / 2) * canvas->x_increments);
	y_midscreen_canvas_value = canvas->y_coordinate_zero - ((HEIGHT / 2) * canvas->y_decrements);
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		canvas->x_increments *= canvas->minus_zoom;
		canvas->y_decrements *= canvas->minus_zoom;
		canvas->x_coordinate_zero = x_midscreen_canvas_value - ((WIDTH / 2) * canvas->x_increments);
		canvas->y_coordinate_zero = y_midscreen_canvas_value + ((HEIGHT / 2) * canvas->y_decrements);
	}
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		canvas->x_increments *= canvas->plus_zoom;
		canvas->y_decrements *= canvas->plus_zoom;
		canvas->x_coordinate_zero = x_midscreen_canvas_value - ((WIDTH / 2) * canvas->x_increments);
		canvas->y_coordinate_zero = y_midscreen_canvas_value + ((HEIGHT / 2) * canvas->y_decrements);
	}
}
