/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:54 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 16:54:38 by fras          ########   odam.nl         */
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

void	show_menu(mlx_t *mlx, mlx_image_t *menu[])
{
	int	x;
	int	y;
	int	item;

	x = 20;
	y = 0;
	item = 0;
	menu[item++] = mlx_put_string(mlx, get(wasd_arrow_navigate), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(plus_min_zoom), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(r_restart), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(c_canvas), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(f_fps), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(m_menu), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(o_other_color), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(p_psychedelic), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(u_ultimate_psychedelic), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(julia_coordinates), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(julia_move1), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get(julia_move2), x, y += 20);
	menu[item++] = mlx_put_string(mlx, "Q or ESC: Exit program", x, y += 20);
}

char	*get(t_menu_lines instruction)
{
	if (instruction == wasd_arrow_navigate)
		return ("WASD or arrows: Move up/left/down/right");
	if (instruction == plus_min_zoom)
		return ("-/+ or scroll-wheel: Zoom in/out");
	if (instruction == r_restart)
		return ("R: Reset to start");
	if (instruction == c_canvas)
		return ("C: Print canvas values");
	if (instruction == f_fps)
		return ("F: Show/hide FPS");
	if (instruction == m_menu)
		return ("M: Show/hide menu");
	if (instruction == o_other_color)
	 	return ("O: Other color");
	if (instruction == p_psychedelic)
		return ("P: Toggle psychedelic mode");
	if (instruction == u_ultimate_psychedelic)
		return ("U: Toggle ULTIMATE psychedelic mode");
	if (instruction == julia_coordinates)
		return ("Left mouse: Get julia coordinates");
	if (instruction == julia_move1)
		return ("CTRL + left mouse: Move to julia-");
	if (instruction == julia_move2)
		return ("coordinates or back to mandelbrot");
	return (NULL);
}
