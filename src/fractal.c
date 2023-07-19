/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:19:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/19 17:36:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_fractal(t_mlx_data *window)
{
	if(!create_fractal(window))
		return (false);
	if (!insert_fractal(window))
		return(false);
	return (true);
}

bool	create_fractal(t_mlx_data *window)
{
	window->background = mlx_new_image(window->mlx, 1440, 900);
	if (!window->background)
		return (false);
	window->image = draw_rect(window->mlx, 1440, 900, 0x6432ffff);
	if (!window->image)
		return (false);
	return (true);
}

bool	insert_fractal(t_mlx_data *window)
{
	if (mlx_image_to_window(window->mlx, window->background, 0, 0) == -1)
		return (false);
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1)
		return (false);
	return (true);
}