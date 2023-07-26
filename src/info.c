/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 17:57:54 by fras          #+#    #+#                 */
/*   Updated: 2023/07/26 17:58:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
