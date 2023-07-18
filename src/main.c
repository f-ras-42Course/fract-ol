/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/18 14:40:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	test_draw_crosshair(mlx_image_t	*image);

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(1440, 900, "MLX Screen!", false);
	if (!mlx)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	image = mlx_new_image(mlx, 1440, 900);
	if (!image)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return(unexpected_crash(mlx), EXIT_FAILURE);
	// mlx_put_pixel(image, 720, 450, 0xffffffff);
	test_draw_crosshair(image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("MLX Success - terminated.\n");
	return (0);
}

void	test_draw_crosshair(mlx_image_t	*image)
{
	int i;

	i = 0;
	while(i != 1440)
		mlx_put_pixel(image, i++, 450, 0xffffffff);
	i = 0;
	while(i != 900)
		mlx_put_pixel(image, 720, i++, 0xffffffff);
}