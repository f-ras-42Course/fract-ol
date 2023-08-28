/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   psychedelic.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 21:37:27 by fras          #+#    #+#                 */
/*   Updated: 2023/08/28 21:56:46 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_psycmode(uint32_t color_scheme[])
{
	if (color_scheme[PSYC_MODE] == true)
		color_scheme[PSYC_MODE] = false;
	else
		color_scheme[PSYC_MODE] = true;
}

void	toggle_ultimate_psycmode(uint32_t color_scheme[], \
		int toggle_psycmode_check)
{
	if (toggle_psycmode_check == -2)
	{
		if (color_scheme[ULTIMATE_PSYC_MODE] == true)
		{
			color_scheme[ULTIMATE_PSYC_MODE] = false;
			color_scheme[PSYC_MODE] = false;
		}
		else
			color_scheme[ULTIMATE_PSYC_MODE] = true;
		return ;
	}
	if (toggle_psycmode_check == -1)
		toggle_psycmode(color_scheme);
	if (toggle_psycmode_check >= 20)
		toggle_psycmode(color_scheme);
}
