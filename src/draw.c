/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:03:39 by fras          #+#    #+#                 */
/*   Updated: 2023/07/19 17:07:08 by fras          ########   odam.nl         */
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
	if (!rectangle)
		return (NULL);
	while (y < height)
	{
		mlx_put_pixel(rectangle, x++, y, color);
		if(x >= width)
		{
			x = 0;
			y++;
		}
	}
	return (rectangle);
}