/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_testing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 18:20:52 by fras          #+#    #+#                 */
/*   Updated: 2023/07/18 18:39:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, unsigned int color)
{
	mlx_image_t	*rectangle;
	int			x;
	int			y;

	x = 0;
	y = 0;
	rectangle = mlx_new_image(mlx, width, height);
	while (y <= height)
	{
		printf("x = %d, y = %d\n", x, y);
		mlx_put_pixel(rectangle, x++, y, color);
		if(x > width)
		{
			x = 0;
			y++;
		}
	}
	printf("x = %d, y = %d\n", x, y);
	return (rectangle);
}

void	test_draw_crosshair(void *image_ptr)
{
	mlx_image_t	*image;
	static int	i;
	static bool go_y;

	image = image_ptr;
	while(i != 1440 && !go_y) //if instead of while in case of in loop
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
	while(go_y && i != 900) ////if instead of while in case of in loop
	{
		while ((i + 1) % 10)
			mlx_put_pixel(image, 720, i++, 0xffffffff);
		mlx_put_pixel(image, 720, i++, 0xffffffff);
		printf("put_pixel y %i\n", i);
	}
}