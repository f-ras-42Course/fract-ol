/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 17:12:49 by fras          #+#    #+#                 */
/*   Updated: 2023/08/29 00:25:12 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	chr1;
	unsigned char	chr2;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	chr1 = (unsigned char)s1[i];
	chr2 = (unsigned char)s2[i];
	return (chr1 - chr2);
}

float	atof_fractol(const char *str)
{
	int		i;
	int		sign;
	float	result;
	float	decimal;

	i = 0;
	result = 0.0;
	decimal = 1.0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	return (result * sign / decimal);
}

bool	fr_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
