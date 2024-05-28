/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 14:23:48 by fras          #+#    #+#                 */
/*   Updated: 2024/05/28 12:20:15 by fras          ########   odam.nl         */
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

# define WIDTH 				1440
# define HEIGHT				900
# define PIP_WIDTH 			432
# define PIP_HEIGHT			270

# define MAX_ITERATION		250
# define PSYC_MODE			251
# define ULTIMATE_PSYC_MODE	252

# define MANDELBROT			0
# define JULIA				1
# define BURNINGSHIP		2
# define FERRY				3

# define COLORX				5
# define COLOR0				0x541010ff
# define COLOR1				0x424242ff
# define COLOR2				0x1F2D64ff
# define COLOR3				0x7F6440ff
# define COLOR4				0x105054ff
# define COLORPSYC			0xFFFF99ff
# define BLACK				0x000000ff

# define X					0
# define Y					1
# define MENU_LINES			13

typedef struct s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t	*fractal;
	mlx_image_t	*fractal_pip;
	mlx_image_t	*menu[MENU_LINES];
}	t_mlx_data;

typedef struct s_canvas
{
	int		fractal_type;
	double	x_coordinate_zero;
	double	y_coordinate_zero;
	double	x_size;
	double	y_size;
	double	x_increments;
	double	y_decrements;
	double	plus_zoom;
	double	minus_zoom;
	double	julia[2];
	bool	pip_mode;
}	t_canvas;

typedef struct s_all
{
	t_mlx_data		window;
	t_canvas		canvas;
	t_canvas		canvas_pip;
	uint32_t		color_scheme[MAX_ITERATION + 3];
	uint32_t		color_options[COLORX];
}	t_all;

typedef enum e_menu_lines
{
	wasd_arrow_navigate,
	plus_min_zoom,
	r_restart,
	c_canvas,
	f_fps,
	m_menu,
	o_other_color,
	p_psychedelic,
	u_ultimate_psychedelic,
	julia_coordinates,
	julia_mandel_switch,
	julia_pip,
	q_esp_exit
}	t_menu_lines;

// Args

int			init_args(int argc, char *argv[], double julia[]);
bool		julia_decimals_correct(const char *str1, const char *str2);
bool		julia_decimals_checker(const char *str);

// Errors
void		unexpected_crash(mlx_t *mlx);
void		invalid_julia(void);
void		invalid_args(void);

// Image

bool		init_image(t_mlx_data *window, t_canvas canvas, \
			uint32_t color_scheme[]);
void		put_pixels(mlx_image_t *fractal, int pixel_pos[], \
			int in_set_check, uint32_t color_scheme[]);
mlx_image_t	*init_fractal(mlx_t *mlx, t_canvas canvas, uint32_t color_scheme[]);
mlx_image_t	*draw_fractal(mlx_image_t *fractal, t_canvas canvas, \
			uint32_t color_scheme[]);

// Fractals

void		init_canvas(t_canvas *canvas);
int			calculate_fractal(double canvas_x, \
			double canvas_y, t_canvas canvas);
int			mandelbrot_calc(double x_constant, double y_constant);
int			julia_calc(double x, double y, double julia[]);
int			burningship_calc(double x_constant, double y_constant);
int			ferry_calc(double x_constant, double y_constant);

// Hooks

bool		load_hooks(t_all *data);
void		loop_hooks(void *param);
void		key_hooks(mlx_key_data_t keydata, void *param);
void		mouse_hooks(mouse_key_t button, action_t action, \
						modifier_key_t mods, void *param);
void		scroll_hooks(double xdelta, double ydelta, void *param);
void		image_move_keys(mlx_key_data_t keydata, t_canvas *canvas);
void		image_zoom_keys(mlx_key_data_t keydata, t_canvas *cvs);
void		image_zoom_mouse(double ydelta, mlx_t *mlx, t_canvas *cvs);

// Info

void		show_menu(mlx_t *mlx, mlx_image_t *menu[]);
void		toggle_menu(mlx_image_t	*menu[]);
char		*get(t_menu_lines instruction);
char		*get2(t_menu_lines instruction);
void		show_canvas_data(t_canvas canvas);
void		good_bye_x(void *param);
void		show_fps(bool key_press);

// Mandelbrot and Julia interconnection

void		switch_to_julia(t_all *data, double julia[]);
void		switch_to_mandelbrot(t_all *data);
void		show_julia_coordinates(t_all *data, double julia[]);
void		toggle_fractal_type(t_all *data);
void		julia_coordinates_from_mouse(mlx_t *mlx, t_canvas *canvas);
void		init_julia_in_pip(t_all *data, action_t action);
void		refresh_julia_in_pip(t_all *data);
void		temp_hide_menu_for_pip(mlx_image_t *menu[], \
							bool activate_julia_pip);
bool		init_pip(t_mlx_data *window, t_canvas canvas_pip, \
							uint32_t color_scheme[]);
mlx_image_t	*init_pip_fractal(mlx_t *mlx, t_canvas canvas_pip, \
							uint32_t color_scheme[]);
mlx_image_t	*draw_pip_fractal(mlx_image_t *fractal_pip, \
							t_canvas canvas_pip, uint32_t color_scheme[]);
void		put_pixels_pip(mlx_image_t *fractal, int pixel_pos[], \
							int in_set_check, uint32_t color_scheme[]);
void		init_canvas_pip(t_canvas *canvas_pip);

// Color and dynamic color modes (psychedelic)

int			rgba2color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void		init_color_scheme(uint32_t start_color, uint8_t rgb_increment, \
			uint32_t color_scheme[]);
void		toggle_psycmode(uint32_t color_scheme[]);
void		toggle_ultimate_psycmode(uint32_t color_scheme[], \
			int toggle_psycmode_check);
void		init_color_options(uint32_t color_options[]);
void		other_color(uint32_t color_scheme[], uint32_t color_options[]);

#endif