/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:19:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/28 21:52:36 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_image(t_mlx_data *window, t_canvas canvas, uint32_t color_scheme[])
{
	window->fractal = init_fractal(window->mlx, canvas, color_scheme);
	if (!window->fractal)
		return (false);
	if (mlx_image_to_window(window->mlx, window->fractal, 0, 0) == -1)
		return (false);
	return (true);
}

mlx_image_t	*init_fractal(mlx_t *mlx, t_canvas canvas, uint32_t color_scheme[])
{
	mlx_image_t	*fractal;

	fractal = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!fractal)
		return (NULL);
	fractal = draw_fractal(fractal, canvas, color_scheme);
	return (fractal);
}

mlx_image_t	*draw_fractal(mlx_image_t *fractal, \
			t_canvas canvas, uint32_t color_scheme[])
{
	int			pixel_pos[2];
	double		canvas_pos[2];
	int			in_set_check;

	pixel_pos[X] = 0;
	pixel_pos[Y] = 0;
	canvas_pos[X] = canvas.x_coordinate_zero;
	canvas_pos[Y] = canvas.y_coordinate_zero;
	while (pixel_pos[Y] < HEIGHT)
	{
		while (pixel_pos[X] < WIDTH)
		{
			in_set_check = \
				calculate_fractal(canvas_pos[X], canvas_pos[Y], canvas);
			put_pixels(fractal, pixel_pos, in_set_check, color_scheme);
			pixel_pos[X]++;
			canvas_pos[X] += canvas.x_increments;
		}
		pixel_pos[X] = 0;
		canvas_pos[X] = canvas.x_coordinate_zero;
		pixel_pos[Y]++;
		canvas_pos[Y] -= canvas.y_decrements;
	}
	return (fractal);
}

void	put_pixels(mlx_image_t *fractal, \
		int pixel_pos[], int in_set_check, uint32_t color_scheme[])
{
	static int	psychedelic_depth = -1;

	if (color_scheme[ULTIMATE_PSYC_MODE] \
		&& pixel_pos[X] == WIDTH - 1 && pixel_pos[Y] == HEIGHT - 1)
		toggle_ultimate_psycmode(color_scheme, psychedelic_depth);
	if (in_set_check == psychedelic_depth)
		mlx_put_pixel(fractal, pixel_pos[X], pixel_pos[Y], COLORPSYC);
	else
		mlx_put_pixel(fractal, pixel_pos[X], \
		pixel_pos[Y], color_scheme[in_set_check]);
	if (pixel_pos[X] == WIDTH - 1 && pixel_pos[Y] == HEIGHT - 1)
	{
		if (color_scheme[PSYC_MODE])
			psychedelic_depth++;
		if (!color_scheme[PSYC_MODE] && psychedelic_depth > -1)
			psychedelic_depth--;
	}
	if (psychedelic_depth > MAX_ITERATION)
		psychedelic_depth--;
}
