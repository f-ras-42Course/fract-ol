/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 22:38:16 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 23:58:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	menu[item++] = mlx_put_string(mlx, get(julia_mandel_switch), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get2(julia_pip), x, y += 20);
	menu[item++] = mlx_put_string(mlx, get2(q_esp_exit), x, y += 20);
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
		return ("Right mouse: Get julia coordinates");
	if (instruction == julia_mandel_switch)
		return ("CTRL + right mouse: Switch julia/mandelbrot");
	return (NULL);
}

char	*get2(t_menu_lines instruction)
{
	if (instruction == julia_pip)
		return ("Left mouse: Display julia PIP in mandelbrot");
	if (instruction == q_esp_exit)
		return ("Q or ESC: Exit program");
	return (NULL);
}
