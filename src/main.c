/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/18 18:01:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	load_hooks(mlx_t *mlx);
void	key_hooks(void	*mlx_ptr);

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
	load_hooks(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

void	key_hooks(void	*mlx_ptr)
{
	mlx_t *mlx;

	mlx = mlx_ptr;
	if(mlx_is_key_down(mlx, MLX_KEY_ESCAPE)\
		|| mlx_is_key_down(mlx, MLX_KEY_Q))
		mlx_close_window(mlx);
}

void	good_bye_X(void *param)
{
	param = NULL;
	ft_putstr_fd("You can also close using 'ESC' or 'Q'!\n", STDOUT_FILENO);
}

void	load_hooks(mlx_t *mlx)
{
	mlx_close_hook(mlx, good_bye_X, NULL);
	mlx_loop_hook(mlx, key_hooks, mlx);
}
