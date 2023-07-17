/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:21:53 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 17:39:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

void	unexpected_crash(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	#ifndef DEBUG
		ft_putstr_fd("MLX Crashed. Go into debug mode for more info.\n" \
			, STDERR_FILENO);
	#endif
	return ;
}
