/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/08/18 13:50:41 by fras          ########   odam.nl         */
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
	image_move_keys(keydata, canvas);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		show_fps(true);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		show_canvas_data(*canvas);
	image_zoom_keys(keydata, canvas);
}

void	scroll_hooks(double xdelta, double ydelta, void* param)
{
	t_all		*data;

	xdelta = 0;
	data = param;
	if (ydelta != 0)
		image_zoom_mouse(ydelta, data->window.mlx, &data->canvas);
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
}

