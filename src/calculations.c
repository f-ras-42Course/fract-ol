/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/26 14:37:48 by fras          #+#    #+#                 */
/*   Updated: 2023/08/28 20:59:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_fractal(double x, double y, t_canvas canvas)
{
	if (canvas.fractal_type == MANDELBROT)
		return (mandelbrot_calc(x, y));
	if (canvas.fractal_type == JULIA)
		return (julia_calc(x, y, canvas.julia));
	return (-1);
}

int	mandelbrot_calc(double x_constant, double y_constant)
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

int	julia_calc(double x, double y, float julia[])
{
	double	xtemp;
	int		i;

	i = 0;
	while ((x * x) + (y * y) < 4 && i++ < MAX_ITERATION - 1)
	{
		xtemp = x;
		x = (x * x) - (y * y) + julia[X];
		y = 2 * y * xtemp + julia[Y];
	}
	return (i);
}
