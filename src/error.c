/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:21:53 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 15:45:46 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	unexpected_crash(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	mlx_strerror(mlx_errno);
	return ;
}
