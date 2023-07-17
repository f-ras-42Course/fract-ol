/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:23:48 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 15:46:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

// typedef struct	s_mlx_general
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*background;
// }	t_mlx_general; //- eventually struct not needed.

void	unexpected_crash(mlx_t *mlx);

#endif