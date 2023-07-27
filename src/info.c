/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:54 by fras          #+#    #+#                 */
/*   Updated: 2023/07/27 02:24:55 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_fps(bool key_press)
{
	static int	second;
	static int	frames;
	static bool fps_on;

	if (key_press && !fps_on)
		fps_on = true;
	else if (key_press && fps_on)
		fps_on = false;
	else
		frames++;
	if(mlx_get_time() > second)
	{
		if (fps_on)
			printf("%d FPS\n", frames);
		second++;
		frames = 0;
	}
}

void	good_bye_X(void *param)
{
	param = NULL;
	if (param)
		return ;
	ft_putstr_fd("You can also close using 'ESC' or 'Q'!\n", STDOUT_FILENO);
}

void	show_canvas_data(t_canvas canvas)
{
	printf("CANVAS DATA = \
	// \ncanvas->x_coordinate_zero = %f\
	// \ncanvas->y_coordinate_zero = %f\
	// \ncanvas->x_increments = %f\
	// \ncanvas->y_decrements= %f\n", canvas.x_coordinate_zero, canvas.y_coordinate_zero, canvas.x_increments, canvas.y_decrements);
}