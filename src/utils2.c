/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:19:24 by fras          #+#    #+#                 */
/*   Updated: 2023/08/30 21:02:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	fractal_float_int_printer(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	fip_format_handler(ap, format, fd);
	va_end(ap);
}

void		fip_format_handler(va_list ap, const char *format, int fd)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				goto print;
			if (*format == 'f')
				fractal_putfloat_fd(ap, 6, fd);
			if (*format == '.')
				format = fractal_putfloat_dflag_fd(ap, format, fd);
			if (*format == 'd' || *format == 'i')
				fractal_putnbr_fd_pt1(ap, fd);
			format++;
		}
		else
		{
			print:
			ft_putchar_fd(*format, fd);
			format++;
		}
	}
}

const char	*fractal_putfloat_dflag_fd(va_list ap, const char *format, int fd)
{
	int flag;;

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
	int start;
	double n;

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

void	fractal_putnbr_fd_pt1(va_list ap, int fd)
{
	int	n;

	n = va_arg(ap, int);
	fractal_putnbr_fd_pt2(n, fd);
}

void	fractal_putnbr_fd_pt2(int n, int fd)
{
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	if (n >= 10)
	{
		fractal_putnbr_fd_pt2(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			ft_putchar_fd('-', fd);
			n *= -1;
			fractal_putnbr_fd_pt2(n, fd);
		}
	}
}
