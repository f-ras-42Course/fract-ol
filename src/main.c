/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 14:26:38 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*background;

	mlx = mlx_init(1440, 900, "MLX Screen!", false);
	if (!mlx)
		return (EXIT_FAILURE);
	background = mlx_new_image(mlx, 0, 0);
	if (!background)
		return (EXIT_FAILURE);
	mlx_loop(mlx);
	printf("MLX terminated.\n");
	return (0);
}
