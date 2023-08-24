/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/08/24 18:08:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->window.mlx, key_hooks, data);
	mlx_scroll_hook(data->window.mlx, scroll_hooks, data);
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
	if (data->color_scheme[ULTIMATE_PSYC_MODE])
		other_color(data->color_scheme, data->color_options);
	image_hooks(&data->window, &data->canvas, data->color_scheme);
	show_fps(0);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_all		*data;
	t_canvas	*canvas;
	
	data = param;
	canvas = &data->canvas;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			mlx_close_window(data->window.mlx);
		if (keydata.key == MLX_KEY_F)
			show_fps(true);
		if (keydata.key == MLX_KEY_C)
			show_canvas_data(*canvas);
		if (keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_EQUAL)
			image_zoom_keys(keydata, canvas);
		if (keydata.key == MLX_KEY_R)
			init_canvas(canvas);
		if (keydata.key == MLX_KEY_M)
			toggle_menu(data->window.menu);
		if (keydata.key == MLX_KEY_P)
			toggle_psycmode(data->color_scheme);
		if (keydata.key == MLX_KEY_O)
			other_color(data->color_scheme, data->color_options);
		if (keydata.key == MLX_KEY_U)
			toggle_ultimate_psycmode(data->color_scheme, -2);
		image_move_keys(keydata, canvas);
	}
}

void	scroll_hooks(double xdelta, double ydelta, void* param)
{
	t_all		*data;

	xdelta = 0;
	ydelta += xdelta;
	data = param;
	if (ydelta != 0)
		image_zoom_mouse(ydelta, data->window.mlx, &data->canvas);
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas, uint32_t color_scheme[])
{
	draw_mandelbrot(window->image, canvas, color_scheme);
}