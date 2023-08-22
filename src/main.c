/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/22 21:41:55 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_all		data;
	uint32_t	color_scheme[MAX_ITERATION + 1];

	data.window.mlx = mlx_init(WIDTH, HEIGHT, "Fractality! - yeah", false);
	if (!data.window.mlx)
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	init_canvas(&data.canvas);
	init_color_scheme(0x1247aaff, 1, 1, 1, color_scheme);
	// int i = 0;
	// while (i < MAX_ITERATION + 1)
	// {
	// 	printf("%d: %x\n", i, color_scheme[i]);
	// 	i++;
	// }
	if(!init_fractal(&data.window, &data.canvas))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	if(!load_hooks(&data))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	mlx_loop(data.window.mlx);
	mlx_terminate(data.window.mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

