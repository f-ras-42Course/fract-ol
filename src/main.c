/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/22 08:42:12 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_mlx_data *window);
void	key_hooks(void *param);

int	main(void)
{
	t_mlx_data window;

	window.mlx = mlx_init(1440, 900, "Fractality! - yeah", false);
	if (!window.mlx)
		return (unexpected_crash(window.mlx), EXIT_FAILURE);
	if(!init_fractal(&window))
		return (unexpected_crash(window.mlx), EXIT_FAILURE);
	if(!load_hooks(&window))
		return (unexpected_crash(window.mlx), EXIT_FAILURE);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

void	key_hooks(void *param)
{
	t_mlx_data *window;

	window = param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_Q))
		mlx_close_window(window->mlx);
	if (mlx_is_key_down(window->mlx, MLX_KEY_W)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_UP))
		window->image->instances->y -= 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_A)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
		window->image->instances->x -= 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_S)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
		window->image->instances->y += 5;
	if (mlx_is_key_down(window->mlx, MLX_KEY_D)\
		|| mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
		window->image->instances->x += 5;
}

void	good_bye_X(void *param)
{
	param = NULL;
	if (param)
		return ;
	ft_putstr_fd("You can also close using 'ESC' or 'Q'!\n", STDOUT_FILENO);
}

bool	load_hooks(t_mlx_data *window)
{
	mlx_close_hook(window->mlx, good_bye_X, NULL);
	return (mlx_loop_hook(window->mlx, key_hooks, window));
}
