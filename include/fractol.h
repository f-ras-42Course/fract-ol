/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:23:48 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 18:02:10 by fras          ########   odam.nl         */
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

# define WIDTH 1440
# define HEIGHT 900
# define MAX_ITERATION 100
# define X 0
# define Y 1
# define COLOR1 0x424242ff
# define COLOR2 0x6432ffff

typedef struct s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t *image;
}	t_mlx_data;

typedef struct s_canvas
{
	int	x_coordinate_zero;
	int y_coordinate_zero;
	int x_size;
	int y_size;
	float x_increments;
	float y_decrements;
	float plus_zoom;
	float minus_zoom;
}	t_canvas;

typedef struct t_all
{
	t_mlx_data	window;
	t_canvas	canvas;
}	t_all;

//Background
mlx_image_t	*draw_rectangle(mlx_t *mlx, int width, int height, unsigned int color);

//Fractal
bool		create_fractal(t_mlx_data *window, t_canvas *canvas);
bool		insert_fractal(t_mlx_data *window);
bool		init_fractal(t_mlx_data *window, t_canvas *canvas);
void		put_fractal_pixel(mlx_image_t *mandelbrot, int  pixel_pos[], double canvas_pos[]);

//Types
mlx_image_t	*init_mandelbrot(mlx_t *mlx, t_canvas *canvas);
mlx_image_t	*draw_mandelbrot(mlx_image_t *mandelbrot, t_canvas *canvas);

int	calculate_mandelbrot(double x_constant, double y_constant);

void	init_canvas(t_canvas *canvas);


// Hooks

bool	load_hooks(t_all *data);
void	loop_hooks(void *param);
void	key_hooks(t_mlx_data *window);
void	image_hooks(t_mlx_data *window, t_canvas *canvas);
void	show_fps(void);
void	good_bye_X(void *param);


#endif