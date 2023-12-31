/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/08/30 21:36:11 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_all			data;

	data.canvas.fractal_type = init_args(argc, argv, data.canvas.julia);
	if (data.canvas.fractal_type == -1)
		return (EXIT_FAILURE);
	data.window.mlx = mlx_init(WIDTH, HEIGHT, "Fractality! - yeah", false);
	if (!data.window.mlx)
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	init_canvas(&data.canvas);
	init_color_options(data.color_options);
	init_color_scheme(data.color_options[0], 1, data.color_scheme);
	data.color_scheme[PSYC_MODE] = false;
	data.color_scheme[ULTIMATE_PSYC_MODE] = false;
	if (!init_image(&data.window, data.canvas, data.color_scheme))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	show_menu(data.window.mlx, data.window.menu);
	if (!load_hooks(&data))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	mlx_loop(data.window.mlx);
	mlx_terminate(data.window.mlx);
	ft_putstr_fd("\nFRACTOL Success - terminated.\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
