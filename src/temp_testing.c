#include "fractol.h"

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