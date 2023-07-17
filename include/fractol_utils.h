/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 17:15:16 by fras          #+#    #+#                 */
/*   Updated: 2023/07/17 17:25:39 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

# include "fractol.h"

void	unexpected_crash(mlx_t *mlx);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif