/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 19:36:03 by fras          #+#    #+#                 */
/*   Updated: 2023/08/22 21:11:39 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgba2color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint32_t color;

	color |= r << 24;
	color |= g << 16;
	color |= b << 8;
	color |= a;
	return (color);
}

void	init_color_scheme(int start_color, int r_o, int g_o, int b_o,\
		 int *color_scheme)
{
	// int i;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	r = (start_color & 0xff000000) >> 24;
	g = (start_color & 0x00ff0000) >> 16;
	b = (start_color & 0x0000ff00) >> 8;
	a = (start_color & 0x000000ff);
	// i = 0;
	// while (i < MAX_ITERATION)
	// 	rgba2color()
}
