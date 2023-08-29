/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 23:59:56 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data)
{
	mlx_key_hook(data->window.mlx, key_hooks, data);
	mlx_scroll_hook(data->window.mlx, scroll_hooks, data);
	mlx_close_hook(data->window.mlx, good_bye_x, NULL);
	mlx_mouse_hook(data->window.mlx, mouse_hooks, data);
	return (mlx_loop_hook(data->window.mlx, loop_hooks, data));
}

void	loop_hooks(void *param)
{
	t_all	*data;

	data = param;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE) \
		|| mlx_is_key_down(data->window.mlx, MLX_KEY_Q))
		mlx_close_window(data->window.mlx);
	if (data->color_scheme[ULTIMATE_PSYC_MODE])
		other_color(data->color_scheme, data->color_options);
	draw_fractal(data->window.fractal, data->canvas, data->color_scheme);
	if (mlx_is_mouse_down(data->window.mlx, MLX_MOUSE_BUTTON_LEFT) \
		&& data->canvas.fractal_type == MANDELBROT)
		refresh_julia_in_pip(data);
	show_fps(0);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_all	*data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			mlx_close_window(data->window.mlx);
		if (keydata.key == MLX_KEY_F)
			show_fps(true);
		if (keydata.key == MLX_KEY_C)
			show_canvas_data(data->canvas);
		if (keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_EQUAL)
			image_zoom_keys(keydata, &data->canvas);
		if (keydata.key == MLX_KEY_R)
			init_canvas(&data->canvas);
		if (keydata.key == MLX_KEY_M)
			toggle_menu(data->window.menu);
		if (keydata.key == MLX_KEY_P)
			toggle_psycmode(data->color_scheme);
		if (keydata.key == MLX_KEY_O)
			other_color(data->color_scheme, data->color_options);
		if (keydata.key == MLX_KEY_U)
			toggle_ultimate_psycmode(data->color_scheme, -2);
		image_move_keys(keydata, &data->canvas);
	}
}

void	scroll_hooks(double xdelta, double ydelta, void *param)
{
	t_all		*data;

	xdelta = 0;
	ydelta += xdelta;
	data = param;
	if (ydelta != 0)
		image_zoom_mouse(ydelta, data->window.mlx, &data->canvas);
}

void	mouse_hooks(mouse_key_t button, action_t action, \
		modifier_key_t mods, void *param)
{
	t_all	*data;

	data = param;
	if (action == MLX_PRESS)
	{
		if (mods == MLX_CONTROL && button == MLX_MOUSE_BUTTON_RIGHT)
			toggle_fractal_type(data);
		else if (button == MLX_MOUSE_BUTTON_RIGHT \
			&& data->canvas.fractal_type == MANDELBROT)
			show_julia_coordinates(data, data->canvas.julia);
		if (button == MLX_MOUSE_BUTTON_LEFT \
			&& data->canvas.fractal_type == MANDELBROT)
		{
			temp_hide_menu_for_pip(data->window.menu, true);
			init_julia_in_pip(data, action);
		}
	}
	if (action == MLX_RELEASE)
	{
		temp_hide_menu_for_pip(data->window.menu, false);
		mlx_delete_image(data->window.mlx, data->window.fractal_pip);
	}
}
