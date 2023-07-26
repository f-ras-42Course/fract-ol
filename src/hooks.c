/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:06 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 18:03:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data)
{
	mlx_close_hook(data->window.mlx, good_bye_X, NULL);
	return (mlx_loop_hook(data->window.mlx, loop_hooks, data));
}

void	loop_hooks(void *param)
{
	t_all		*data;
	data = param;

	key_hooks(&data->window);
	image_hooks(&data->window, &data->canvas);
	show_fps();
}

void	key_hooks(t_mlx_data *window)
{
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_Q))
		mlx_close_window(window->mlx);
	if (mlx_is_key_down(window->mlx, MLX_KEY_W)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_UP))
		window->image->instances->y -= 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_A)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
		window->image->instances->x -= 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_S)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
		window->image->instances->y += 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_D)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
		window->image->instances->x += 5;
}

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
	show_fps();
}

