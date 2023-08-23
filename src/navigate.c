/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   navigate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 13:43:51 by fras          #+#    #+#                 */
/*   Updated: 2023/08/23 21:25:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


void	image_move_keys(mlx_key_data_t keydata, t_canvas *canvas)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
		canvas->y_coordinate_zero += (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
		canvas->x_coordinate_zero -= (WIDTH * 0.125) * canvas->x_increments;
	if ((keydata.key == MLX_KEY_S || keydata.key ==MLX_KEY_DOWN))
		canvas->y_coordinate_zero -= (HEIGHT * 0.125) * canvas->y_decrements;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
		canvas->x_coordinate_zero += (WIDTH * 0.125) * canvas->x_increments;
}

void	image_zoom_keys(mlx_key_data_t keydata, t_canvas *cvs)
{
	double	x_start_size;
    double	y_start_size;

	x_start_size = (WIDTH * cvs->x_increments);
	y_start_size = (HEIGHT * cvs->y_decrements);
	if (keydata.key == MLX_KEY_MINUS)
	{
		cvs->x_increments *= cvs->minus_zoom;
		cvs->y_decrements *= cvs->minus_zoom;
	}
	if (keydata.key == MLX_KEY_EQUAL)
	{
		cvs->x_increments *= cvs->plus_zoom;
		cvs->y_decrements *= cvs->plus_zoom;
	}
	cvs->x_coordinate_zero += (x_start_size - (WIDTH * cvs->x_increments)) / 2;
	cvs->y_coordinate_zero -= (y_start_size - (HEIGHT * cvs->y_decrements)) / 2;
}

void    image_zoom_mouse(double ydelta, mlx_t *mlx, t_canvas *cvs)
{
    int32_t	x_mouse_pos;
    int32_t	y_mouse_pos;
	double	x_start_size;
    double	y_start_size;

    x_mouse_pos = 0;
    y_mouse_pos = 0;
    mlx_get_mouse_pos(mlx, &x_mouse_pos, &y_mouse_pos);
	cvs->x_coordinate_zero += (x_mouse_pos - (WIDTH / 2)) * cvs->x_increments;
	cvs->y_coordinate_zero -= (y_mouse_pos - (HEIGHT / 2)) * cvs->y_decrements;
	x_start_size = (WIDTH * cvs->x_increments);
	y_start_size = (HEIGHT * cvs->y_decrements);
    if (ydelta > 0)
    {
        cvs->x_increments *= cvs->plus_zoom;
        cvs->y_decrements *= cvs->plus_zoom;
    }
    if (ydelta < 0)
    {
        cvs->x_increments *= cvs->minus_zoom;
        cvs->y_decrements *= cvs->minus_zoom;
    }
	cvs->x_coordinate_zero += (x_start_size - (WIDTH * cvs->x_increments)) / 2;
	cvs->y_coordinate_zero -= (y_start_size - (HEIGHT * cvs->y_decrements)) / 2;
	mlx_set_mouse_pos(mlx, WIDTH/2, HEIGHT/2);
}

void	show_menu(mlx_t *mlx, mlx_image_t *menu[])
{
	int x;
	int y;
	int item;

	x = 20;
	y = 0;
	item = 0;
	menu[item++] =	mlx_put_string(mlx, "WASD or arrows: Move up/left/down/right", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "-/+ or scroll-wheel: Zoom in/out", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "R: Reset to start", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "C: Print canvas values", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "F: Show/hide FPS", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "M: Show/hide menu", x, y += 20);
	menu[item++] =  mlx_put_string(mlx, "Q or ESC: Exit program", x, y += 20);
}

void	toggle_menu(mlx_image_t	**menu)
{
	int	i;

	i = 0;
	while (i < MENU_INSTRUCTIONS)
	{
		if (menu[i]->enabled == true)
			menu[i]->enabled = false;
		else
			menu[i]->enabled = true;
		i++;
	}
}
