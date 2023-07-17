/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 16:09:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*background;

	mlx = mlx_init(1440, 900, "MLX Screen!", false);
	if (!mlx)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	background = mlx_new_image(mlx, 1440, 900);
	if (!background)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("MLX Success - terminated.\n");
	return (0);
}
