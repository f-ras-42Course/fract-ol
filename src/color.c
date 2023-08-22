/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 19:36:03 by fras          #+#    #+#                 */
/*   Updated: 2023/08/22 20:37:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgba2color(unint8_t r, unint8_t g, unint8_t b, unint8_t a)
{
	r <<= 24;
	g <<= 16;
	b <<= 8;
	return(r | g | b | a);
}

void	init_color_scheme()
{

}
