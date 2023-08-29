/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:21:53 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 02:35:59 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

void	unexpected_crash(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	if (!DEBUG)
		ft_putstr_fd("Fractol: MLX Crashed. Go into debug mode for more info.\n\
			", STDERR_FILENO);
	return ;
}

void	invalid_args(void)
{
	ft_putstr_fd("\n---Fractol: Invalid arguments.---\n\n", STDERR_FILENO);
	ft_putstr_fd("Please make sure you run the correct command:\n\n", \
				STDERR_FILENO);
	ft_putstr_fd("For Mandelbrot run:	./fractol mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("For Burningman run:	./fractol burningman\n", STDERR_FILENO);
	ft_putstr_fd("For Julia run:	 	./fractol julia [x-value] [y-value]\n\n", \
				STDERR_FILENO);
	ft_putstr_fd("Mandelbrot & Burningman has no other arguments,\n", \
				STDERR_FILENO);
	ft_putstr_fd("\nExample for Julia:	./fractol \"julia\" \"0.3\" \"0.6\"\n", \
				STDERR_FILENO);
	ft_putstr_fd("The first argument after julia is the 'x' value and " \
				"the second is the 'y' value. ", STDERR_FILENO);
	ft_putstr_fd("Please note that it is not allowed to use more than " \
				"6 decimals and no less than 1 decimal. ", STDERR_FILENO);
	ft_putstr_fd("The value cannot be higher or lower than 10 or -10.\n\n"\
				, STDERR_FILENO);
}

void	invalid_julia(void)
{
	ft_putstr_fd("\n---Fractol: Julia command invalid.---\n\n", STDERR_FILENO);
	ft_putstr_fd("Please make sure you run the correct command:\n\n", \
				STDERR_FILENO);
	ft_putstr_fd("Example:	./fractol julia 0.3 0.6\n\n", \
				STDERR_FILENO);
	ft_putstr_fd("The first argument after julia is the 'x' value and " \
				"the second is the 'y' value. ", STDERR_FILENO);
	ft_putstr_fd("Please note that it is not allowed to use more than " \
				"6 decimals and no less than 1 decimal. ", STDERR_FILENO);
	ft_putstr_fd("The value cannot be higher or lower than 10 or -10.\n\n"\
				, STDERR_FILENO);
}
