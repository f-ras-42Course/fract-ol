/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:54:51 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 17:55:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_image_t	*init_mandelbrot(mlx_t *mlx, t_canvas *canvas)
{

	mlx_image_t	*mandelbrot;

	mandelbrot = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mandelbrot)
		return (NULL);
	mandelbrot = draw_mandelbrot(mandelbrot, canvas);
	return (mandelbrot);
}

mlx_image_t	*draw_mandelbrot(mlx_image_t *mandelbrot, t_canvas *canvas)
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
			put_fractal_pixel(mandelbrot, pixel_pos, canvas_pos);
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

void	put_fractal_pixel(mlx_image_t *mandelbrot, int  pixel_pos[], double canvas_pos[])
{
	int			in_set_check;

	in_set_check = calculate_mandelbrot(canvas_pos[X], canvas_pos[Y]);
	if (in_set_check < MAX_ITERATION)
		mlx_put_pixel(mandelbrot, pixel_pos[X], pixel_pos[Y], COLOR2);
	else
		mlx_put_pixel(mandelbrot, pixel_pos[X], pixel_pos[Y], COLOR1);
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
	while ((x * x) + (y * y) < 4 && i++ < MAX_ITERATION)
	{
		xtemp = x;
		x = (x * x) - (y * y) + x_constant;
		y = 2 * y * xtemp + y_constant;
		i++;
	}
	return (i);
}
