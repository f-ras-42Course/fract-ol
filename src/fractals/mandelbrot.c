/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:54:51 by fras          #+#    #+#                 */
/*   Updated: 2023/08/23 15:44:02 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_image_t	*init_mandelbrot(mlx_t *mlx, t_canvas *canvas, uint32_t color_scheme[])
{

	mlx_image_t	*mandelbrot;

	mandelbrot = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mandelbrot)
		return (NULL);
	mandelbrot = draw_mandelbrot(mandelbrot, canvas, color_scheme);
	return (mandelbrot);
}

mlx_image_t	*draw_mandelbrot(mlx_image_t *mandelbrot, t_canvas *canvas, uint32_t color_scheme[])
{
	int			pixel_pos[2];
	double		canvas_pos[2];

	pixel_pos[X] = 0;
	pixel_pos[Y] = 0;
	canvas_pos[X] = canvas->x_coordinate_zero;
	canvas_pos[Y] = canvas->y_coordinate_zero;
	while (pixel_pos[Y] < HEIGHT)
	{
		while (pixel_pos[X] < WIDTH)
		{
			put_fractal_pixel(mandelbrot, pixel_pos, canvas_pos, color_scheme);
			pixel_pos[X]++;
			canvas_pos[X] += canvas->x_increments;
		}
		pixel_pos[X] = 0;
		canvas_pos[X] = canvas->x_coordinate_zero;
		pixel_pos[Y]++;
		canvas_pos[Y] -= canvas->y_decrements;
	}
	return(mandelbrot);
}

void	put_fractal_pixel(mlx_image_t *mandelbrot, int  pixel_pos[], double canvas_pos[], uint32_t color_scheme[])
{
	int			in_set_check;

	in_set_check = calculate_mandelbrot(canvas_pos[X], canvas_pos[Y]);
	mlx_put_pixel(mandelbrot, pixel_pos[X], pixel_pos[Y], color_scheme[in_set_check]);
}

int	calculate_mandelbrot(double x_constant, double y_constant)
{
	double	xtemp;
	double	x;
	double	y;
	int		i;

	x = x_constant;
	y = y_constant;
	i = 0;
	while ((x * x) + (y * y) < 4 && i++ < MAX_ITERATION - 1)
	{
		xtemp = x;
		x = (x * x) - (y * y) + x_constant;
		y = 2 * y * xtemp + y_constant;
	}
	return (i);
}
