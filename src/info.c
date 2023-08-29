/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:54 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 22:39:06 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_fps(bool key_press)
{
	static int	second;
	static int	frames;
	static bool	fps_on;

	if (key_press && !fps_on)
		fps_on = true;
	else if (key_press && fps_on)
		fps_on = false;
	else
		frames++;
	if (mlx_get_time() > second)
	{
		if (fps_on)
			printf("%d FPS\n", frames);
		second++;
		frames = 0;
	}
}

void	good_bye_x(void *param)
{
	param = NULL;
	if (param)
		return ;
	ft_putstr_fd("You can also close using 'ESC' or 'Q'!\n", STDOUT_FILENO);
}

void	show_canvas_data(t_canvas canvas)
{
	printf("-----------------------------------------\n\
		\n|  CANVAS DATA = \
		\n|  canvas->x_coordinate_zero = %f\
		\n|  canvas->y_coordinate_zero = %f\
		\n|  canvas->x_increments = %f\
		\n|  canvas->y_decrements= %f\n\
	\n-----------------------------------------\n", \
	canvas.x_coordinate_zero, canvas.y_coordinate_zero, \
	canvas.x_increments, canvas.y_decrements);
}

void	show_julia_coordinates(t_all *data, float julia[])
{
	julia_coordinates_from_mouse(data->window.mlx, &data->canvas);
	printf("Julia coordinates are: %f, %f\n", julia[X], julia[Y]);

}