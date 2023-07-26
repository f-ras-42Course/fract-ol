/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:48:09 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 17:52:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	load_hooks(t_all *data);
void	loop_hooks(void *param);
void	key_hooks(t_mlx_data *window);
void	image_hooks(t_mlx_data *window, t_canvas *canvas);
void	show_fps(void);
void	good_bye_X(void *param);


int	main(void)
{
	t_all		data;

	data.window.mlx = mlx_init(WIDTH, HEIGHT, "Fractality! - yeah", false);
	if (!data.window.mlx)
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	init_canvas(&data.canvas);
	if(!init_fractal(&data.window, &data.canvas))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	if(!load_hooks(&data))
		return (unexpected_crash(data.window.mlx), EXIT_FAILURE);
	mlx_loop(data.window.mlx);
	// mandelbrot_tester();
	mlx_terminate(data.window.mlx);
	printf("\nFRACTOL Success - terminated.\n");
	return (EXIT_SUCCESS);
}

void	init_canvas(t_canvas *canvas)
{
	canvas->x_coordinate_zero = -2;
	canvas->y_coordinate_zero = 1;
	canvas->x_size = 3;
	canvas->y_size = 2;
	canvas->x_increments = (float)canvas->x_size/(WIDTH - 1);
	canvas->y_decrements = (float)canvas->y_size/(HEIGHT - 1);
	canvas->plus_zoom = 1.01;
	canvas->minus_zoom = 0.99;
}


bool	load_hooks(t_all *data)
{
	mlx_close_hook(data->window.mlx, good_bye_X, NULL);
	return (mlx_loop_hook(data->window.mlx, loop_hooks, data));
}

void	loop_hooks(void *param)
{
	t_all		*data;
	data = param;

	key_hooks(&data->window);
	image_hooks(&data->window, &data->canvas);
	show_fps();
}

void	key_hooks(t_mlx_data *window)
{
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

void	image_hooks(t_mlx_data *window, t_canvas *canvas)
{
	draw_mandelbrot(window->image, canvas);
	show_fps();
}

void	show_fps(void)
{
	static int	second;
	static int	frames;

	frames++;
	if(mlx_get_time() > second)
	{
		printf("%d FPS\n", frames);
		second++;
		frames = 0;
	}
}

void	good_bye_X(void *param)
{
	param = NULL;
	if (param)
		return ;
	ft_putstr_fd("You can also close using 'ESC' or 'Q'!\n", STDOUT_FILENO);
}

