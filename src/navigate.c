/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   navigate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 13:43:51 by fras          #+#    #+#                 */
/*   Updated: 2023/08/18 15:08:26 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


void	image_move_keys(mlx_key_data_t keydata, t_canvas *canvas)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
		canvas->y_coordinate_zero += (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
		canvas->x_coordinate_zero -= (WIDTH * 0.125) * canvas->x_increments;
	if ((keydata.key == MLX_KEY_S || keydata.key ==MLX_KEY_DOWN))
		canvas->y_coordinate_zero -= (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
		canvas->x_coordinate_zero += (WIDTH * 0.125) * canvas->x_increments;
}

void	image_zoom_keys(mlx_key_data_t keydata, t_canvas *canvas)
{
	double	x_midscreen_canvas_value;
	double	y_midscreen_canvas_value;
	
	x_midscreen_canvas_value = \
		canvas->x_coordinate_zero + ((WIDTH / 2) * canvas->x_increments);
	y_midscreen_canvas_value = \
		canvas->y_coordinate_zero - ((HEIGHT / 2) * canvas->y_decrements);
	if (keydata.key == MLX_KEY_MINUS)
	{
		canvas->x_increments *= canvas->minus_zoom;
		canvas->y_decrements *= canvas->minus_zoom;
	}
	if (keydata.key == MLX_KEY_EQUAL)
	{
		canvas->x_increments *= canvas->plus_zoom;
		canvas->y_decrements *= canvas->plus_zoom;
	}
	canvas->x_coordinate_zero = \
		x_midscreen_canvas_value - ((WIDTH / 2) * canvas->x_increments);
	canvas->y_coordinate_zero = \
		y_midscreen_canvas_value + ((HEIGHT / 2) * canvas->y_decrements);
}

void    image_zoom_mouse(double ydelta, mlx_t *mlx, t_canvas *canvas)
{
    int32_t x_mouse_pos;
    int32_t y_mouse_pos;

    x_mouse_pos = 0;
    y_mouse_pos = 0;
    mlx_get_mouse_pos(mlx, &x_mouse_pos, &y_mouse_pos);
    if (ydelta > 0)
    {
        canvas->x_increments *= canvas->plus_zoom;
        canvas->y_decrements *= canvas->plus_zoom;
    }
    if (ydelta < 0)
    {
        canvas->x_increments *= canvas->minus_zoom;
        canvas->y_decrements *= canvas->minus_zoom;
    }
	canvas->x_coordinate_zero += (x_mouse_pos - (WIDTH / 2)) * canvas->x_increments;
	canvas->y_coordinate_zero -= (y_mouse_pos - (HEIGHT / 2)) * canvas->y_decrements;
}
