/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:23:48 by fras          #+#    #+#                 */
/*   Updated: 2023/08/23 22:27:15 by fras          ########   odam.nl         */
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
# include <stdint.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define WIDTH 1440
# define HEIGHT 900
# define MAX_ITERATION 250
# define MENU_INSTRUCTIONS 8
# define X 0
# define Y 1
# define PSYC_MODE MAX_ITERATION+1
# define COLOR1 0x541010ff
# define COLOR2 0x424242ff
# define COLORPSYC 0xEFEF5Cff
# define BLACK	0x000000ff

typedef struct s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t *image;
	mlx_image_t *menu[MENU_INSTRUCTIONS];
}	t_mlx_data;

typedef struct s_canvas
{
	double	x_coordinate_zero;
	double	y_coordinate_zero;
	double	x_size;
	double	y_size;
	double	x_increments;
	double	y_decrements;
	double	plus_zoom;
	double	minus_zoom;
}	t_canvas;

typedef struct t_all
{
	t_mlx_data	window;
	t_canvas	canvas;
	uint32_t	color_scheme[MAX_ITERATION + 2];
}	t_all;

//Fractal
bool	create_fractal(t_mlx_data *window, t_canvas *canvas, uint32_t color_scheme[]);
bool	insert_fractal(t_mlx_data *window);
bool	init_fractal(t_mlx_data *window, t_canvas *canvas, uint32_t color_scheme[]);
void	put_fractal_pixel(mlx_image_t *mandelbrot, int pixel_pos[], double canvas_pos[], uint32_t color_scheme[]);

//Types
mlx_image_t	*init_mandelbrot(mlx_t *mlx, t_canvas *canvas, uint32_t color_scheme[]);
mlx_image_t	*draw_mandelbrot(mlx_image_t *mandelbrot, t_canvas *canvas, uint32_t color_scheme[]);

int	calculate_mandelbrot(double x_constant, double y_constant);

void	init_canvas(t_canvas *canvas);


// Hooks

bool	load_hooks(t_all *data);
void	loop_hooks(void *param);
void	key_hooks(mlx_key_data_t keydata, void *param);
void	scroll_hooks(double xdelta, double ydelta, void* param);
void	image_hooks(t_mlx_data *window, t_canvas *canvas, uint32_t color_scheme[]);
void	show_fps(bool key_press);
void	good_bye_X(void *param);

void	image_move_keys(mlx_key_data_t keydata, t_canvas *canvas);
void	image_zoom_keys(mlx_key_data_t keydata, t_canvas *cvs);
void    image_zoom_mouse(double ydelta, mlx_t *mlx, t_canvas *cvs);

void	show_canvas_data(t_canvas canvas);

void	show_menu(mlx_t *mlx, mlx_image_t *menu[]);
void	toggle_menu(mlx_image_t	**menu);

// Color

int		rgba2color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void	init_color_scheme(uint32_t start_color, uint8_t r_o, uint8_t g_o,\
			uint8_t b_o, uint32_t color_scheme[]);
void	toggle_psycmode(uint32_t color_scheme[]);

#endif