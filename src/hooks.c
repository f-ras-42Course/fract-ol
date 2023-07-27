/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/07/27 18:29:37 by fras          ########   odam.nl         */
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
	static int loops;
	t_all *data;

	data = param;
	loops++;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE)\
		|| mlx_is_key_down(data->window.mlx, MLX_KEY_Q))
		mlx_close_window(data->window.mlx);
	if (loops == 10)
	{
		image_hooks(&data->window, &data->canvas);
		loops = 0;
	}
	show_fps(false);
	// printf("FIRSTCALL: %d, SECONDCALL %d\n", get_fps(), get_fps());
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_all *data;
	t_canvas *canvas;
	
	data = param;
	canvas = &data->canvas;
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS))
		mlx_close_window(data->window.mlx);
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		canvas->y_coordinate_zero *= 1.25;
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)\
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		canvas->x_coordinate_zero *= 1.25;
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)\
		|| (keydata.key ==MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		canvas->y_coordinate_zero *= 0.75;
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)\
	|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		canvas->x_coordinate_zero *= 0.75;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		show_fps(true);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		show_canvas_data(*canvas);
	image_zoom(keydata, canvas);
	// printf("Show time: %f\n", mlx_get_time());
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
}

void	image_zoom(mlx_key_data_t keydata, t_canvas *canvas)
{
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		canvas->x_coordinate_zero *= canvas->minus_zoom;
		canvas->y_coordinate_zero *= canvas->minus_zoom;
		canvas->x_increments *= canvas->minus_zoom;
		canvas->y_decrements *= canvas->minus_zoom;
	}
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		canvas->x_coordinate_zero *= canvas->plus_zoom;
		canvas->y_coordinate_zero *= canvas->plus_zoom;
		canvas->x_increments *= canvas->plus_zoom;
		canvas->y_decrements *= canvas->plus_zoom;
	}
}
