/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 21:06:15 by fras          #+#    #+#                 */
/*   Updated: 2023/08/30 21:29:30 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**	Note to self:
	
	Micro printf made for fractal usage:
	- Handles: float, int and format of string.
	- Handels only until float 9.9999xxx/-9.9999xxx (max/min).
	- Able to handle '%f' and '.xx' for float representation.

	Don't use in other projects before handling inputs correctly. **/

#include "fractol_utils.h"

void	fractal_float_int_printer(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	fip_format_handler(ap, format, fd);
	va_end(ap);
}

void	fip_format_handler(va_list ap, const char *format, int fd)
{
	int	n;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'f')
				fractal_putfloat_fd(ap, 6, fd);
			if (*format == '.')
				format = fractal_putfloat_dflag_fd(ap, format, fd);
			if (*format == 'd' || *format == 'i')
			{
				n = va_arg(ap, int);
				ft_putnbr_fd(n, fd);
			}
			format++;
		}
		else
		{
			ft_putchar_fd(*format, fd);
			format++;
		}
	}
}

const char	*fractal_putfloat_dflag_fd(va_list ap, const char *format, int fd)
{
	int	flag;

	format++;
	flag = 0;
	flag += *format - 48;
	format++;
	while (fr_isdigit(*format))
	{
		flag *= 10;
		flag += *format - 48;
		format++;
	}
	fractal_putfloat_fd(ap, flag, fd);
	return (format);
}

void	fractal_putfloat_fd(va_list ap, int decimals, int fd)
{
	int		start;
	double	n;

	start = decimals;
	n = va_arg(ap, double);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (decimals + 1)
	{
		if (n < 10)
		{
			ft_putchar_fd(n + '0', fd);
			n -= (int)n;
		}
		if (decimals == start)
			ft_putchar_fd('.', fd);
		n *= 10;
		decimals--; 
	}
}
