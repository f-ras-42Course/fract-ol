/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/18 16:17:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	test_draw_crosshair(void	*image_ptr);
void	load_hooks(mlx_t *mlx, mlx_image_t *image);

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(1440, 900, "Fractality! - yeah", false);
	if (!mlx)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	image = mlx_new_image(mlx, 1440, 900);
	if (!image)
		return (unexpected_crash(mlx), EXIT_FAILURE);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return(unexpected_crash(mlx), EXIT_FAILURE);
	// mlx_put_pixel(image, 720, 450, 0xffffffff);
	// test_draw_crosshair(image);
	load_hooks(mlx, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("MLX Success - terminated.\n");
	return (0);
}

void	test_draw_crosshair(void	*image_ptr)
{
	mlx_image_t	*image;
	static int	i;
	static bool go_y;

	image = image_ptr;
	if(i != 1440 && !go_y)
	{
		while ((i + 1) % 10)
			mlx_put_pixel(image, i++, 450, 0xffffffff);
		mlx_put_pixel(image, i++, 450, 0xffffffff);
		printf("put_pixel x %i\n", i);
	}
	if (i == 1440)
	{
		i = 0;
		go_y = true;
	}
	if(go_y && i != 900)
	{
		while ((i + 1) % 10)
			mlx_put_pixel(image, 720, i++, 0xffffffff);
		mlx_put_pixel(image, 720, i++, 0xffffffff);
		printf("put_pixel y %i\n", i);
	}
}

void	load_hooks(mlx_t *mlx, mlx_image_t *image)
{
	mlx_loop_hook(mlx, test_draw_crosshair, image);
}
