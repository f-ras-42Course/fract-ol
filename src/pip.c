/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pip.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:19:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 23:16:57 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_pip(t_mlx_data *window, t_canvas canvas_pip, uint32_t color_scheme[])
{
	window->fractal_pip = init_pip_fractal(window->mlx, canvas_pip, color_scheme);
	if (!window->fractal_pip)
		return (false);
	if (mlx_image_to_window(window->mlx, window->fractal_pip, 10, 10) == -1)
		return (false);
	return (true);
}

mlx_image_t	*init_pip_fractal(mlx_t *mlx, t_canvas canvas_pip, uint32_t color_scheme[])
{
	mlx_image_t	*fractal_pip;

	fractal_pip = mlx_new_image(mlx, PIP_WIDTH, PIP_HEIGHT);
	if (!fractal_pip)
		return (NULL);
	fractal_pip = draw_pip_fractal(fractal_pip, canvas_pip, color_scheme);
	return (fractal_pip);
}

mlx_image_t	*draw_pip_fractal(mlx_image_t *fractal_pip, \
			t_canvas canvas_pip, uint32_t color_scheme[])
{
	int			pixel_pos[2];
	double		canvas_pos[2];
	int			in_set_check;

	pixel_pos[X] = 0;
	pixel_pos[Y] = 0;
	canvas_pos[X] = canvas_pip.x_coordinate_zero;
	canvas_pos[Y] = canvas_pip.y_coordinate_zero;
	while (pixel_pos[Y] < PIP_HEIGHT)
	{
		while (pixel_pos[X] < PIP_WIDTH)
		{
			in_set_check = \
				julia_calc(canvas_pos[X], canvas_pos[Y], canvas_pip.julia);
			put_pixels_pip(fractal_pip, pixel_pos, in_set_check, color_scheme);
			pixel_pos[X]++;
			canvas_pos[X] += canvas_pip.x_increments;
		}
		pixel_pos[X] = 0;
		canvas_pos[X] = canvas_pip.x_coordinate_zero;
		pixel_pos[Y]++;
		canvas_pos[Y] -= canvas_pip.y_decrements;
	}
	return (fractal_pip);
}
	
void	put_pixels_pip(mlx_image_t *fractal_pip, \
		int pixel_pos[], int in_set_check, uint32_t color_scheme[])
{
	static int	psychedelic_depth = -1;

	if (color_scheme[ULTIMATE_PSYC_MODE] \
		&& pixel_pos[X] == PIP_WIDTH - 1 && pixel_pos[Y] == PIP_HEIGHT - 1)
		toggle_ultimate_psycmode(color_scheme, psychedelic_depth);
	if (in_set_check == psychedelic_depth)
		mlx_put_pixel(fractal_pip, pixel_pos[X], pixel_pos[Y], COLORPSYC);
	else
		mlx_put_pixel(fractal_pip, pixel_pos[X], \
		pixel_pos[Y], color_scheme[in_set_check]);
	if (pixel_pos[X] == PIP_WIDTH - 1 && pixel_pos[Y] == PIP_HEIGHT - 1)
	{
		if (color_scheme[PSYC_MODE])
			psychedelic_depth++;
		if (!color_scheme[PSYC_MODE] && psychedelic_depth > -1)
			psychedelic_depth--;
	}
	if (psychedelic_depth > MAX_ITERATION)
		psychedelic_depth--;
}
