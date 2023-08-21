/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/21 20:45:40 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_all	data;
	// int		colorscheme[MAX_ITERATION + 1];

	data.window.mlx = mlx_init(WIDTH, HEIGHT, "Fractality! - yeah", false);
	if (!data.window.mlx)
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	init_canvas(&data.canvas);
	// init_colorscheme(colorscheme);
	if(!init_fractal(&data.window, &data.canvas))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	if(!load_hooks(&data))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	mlx_loop(data.window.mlx);
	mlx_terminate(data.window.mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

