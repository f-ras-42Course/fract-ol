/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:54 by fras          #+#    #+#                 */
/*   Updated: 2023/08/24 19:03:02 by fras          ########   odam.nl         */
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
void	show_menu(mlx_t *mlx, mlx_image_t *menu[])
{
	int x;
	int y;
	int item;

	x = 20;
	y = 0;
	item = 0;
	menu[item++] =	mlx_put_string(mlx, "WASD or arrows: Move up/left/down/right", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "-/+ or scroll-wheel: Zoom in/out", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "R: Reset to start", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "C: Print canvas values", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "F: Show/hide FPS", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "M: Show/hide menu", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "O: Other color", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "P: Toggle psychedelic mode", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "U: Toggle ULTIMATE psychedelic mode", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "Q or ESC: Exit program", x, y += 20);
}
