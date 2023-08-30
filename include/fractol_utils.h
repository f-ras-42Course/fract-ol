/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 17:15:16 by fras          #+#    #+#                 */
/*   Updated: 2023/08/30 21:28:11 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

# include "fractol.h"
# include <stdarg.h>

void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
float		atof_fractol(const char *str);
bool		fr_isdigit(int c);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);

//	Micro printf starts here (utils3.c)

void		fractal_float_int_printer(int fd, const char *format, ...);
void		fip_format_handler(va_list ap, const char *format, int fd);
/*			fractal_putfloat_fd: max/min value = 9.9999/-9.9999				*/
void		fractal_putfloat_fd(va_list ap, int decimals, int fd);
const char	*fractal_putfloat_dflag_fd(va_list ap, const char *format, int fd);

#endif