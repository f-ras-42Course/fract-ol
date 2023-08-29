/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toggle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 21:37:27 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 14:53:23 by fras          ########   odam.nl         */
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

void	toggle_menu(mlx_image_t	*menu[])
{
	int	i;

	i = 0;
	while (i < MENU_LINES)
	{
		if (menu[i]->enabled == true)
			menu[i]->enabled = false;
		else
			menu[i]->enabled = true;
		i++;
	}
}
