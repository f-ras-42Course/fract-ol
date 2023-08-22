/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 19:36:03 by fras          #+#    #+#                 */
/*   Updated: 2023/08/22 21:36:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgba2color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	uint32_t color;

	color = 0;
	color |= r << 24;
	color |= g << 16;
	color |= b << 8;
	color |= a;
	return (color);
}

void	init_color_scheme(uint32_t start_color, uint8_t r_o, uint8_t g_o,\
			uint8_t b_o, uint32_t color_scheme[])
{
	int i;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	i = 0;
	r = (start_color & 0xff000000) >> 24;
	g = (start_color & 0x00ff0000) >> 16;
	b = (start_color & 0x0000ff00) >> 8;
	a = (start_color & 0x000000ff);
	color_scheme[i++] = rgba2color(r, g, b, a);
	while (i < MAX_ITERATION)
		color_scheme[i++] = rgba2color(r += r_o, g += g_o, b += b_o, a);
	color_scheme[i] = BLACK;
}
