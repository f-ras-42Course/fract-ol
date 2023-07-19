/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:23:48 by fras          #+#    #+#                 */
/*   Updated: 2023/07/19 17:05:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "fractol_utils.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t *rectangle;	
}	t_mlx_data;

mlx_image_t	*draw_rect(mlx_t *mlx, int width, int height, unsigned int color);

#endif