/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 23:08:57 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 19:00:17 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_args(int argc, char *argv[], float julia[])
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 11))
			return (MANDELBROT);
		if (!ft_strncmp(argv[1], "julia", 6))
			return (invalid_julia(), -1);
		if (!ft_strncmp(argv[1], "burningship", 12))
			return (BURNINGSHIP);
	}
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (julia_decimals_correct(argv[2], argv[3]))
		{
			julia[X] = atof_fractol(argv[2]);
			julia[Y] = atof_fractol(argv[3]);
			return (JULIA);
		}
		else
			return (invalid_julia(), -1);
	}
	return (invalid_args(), -1);
}

bool	julia_decimals_correct(const char *str1, const char *str2)
{
	if (!julia_decimals_checker(str1) || !julia_decimals_checker(str2))
		return (false);
	return (true);
}

bool	julia_decimals_checker(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (fr_isdigit(str[i]))
		i++;
	else
		return (false);
	if (str[i] == '.')
		i++;
	else
		return (false);
	while (fr_isdigit(str[i]))
		i++;
	if (str[i] != '\0' || i > 9)
		return (false);
	return (true);
}
