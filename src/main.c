/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/23 17:14:15 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_all		data;

	data.window.mlx = mlx_init(WIDTH, HEIGHT, "Fractality! - yeah", false);
	if (!data.window.mlx)
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	init_canvas(&data.canvas);
	init_color_scheme(0x541010ff, 1, 1, 1, data.color_scheme);
	if(!init_fractal(&data.window, &data.canvas, data.color_scheme))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	if(!load_hooks(&data))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	show_menu(data.window.mlx);
	mlx_loop(data.window.mlx);
	mlx_terminate(data.window.mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

