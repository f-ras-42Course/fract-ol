/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:38:08 by fras          #+#    #+#                 */
/*   Updated: 2023/07/16 19:38:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(256, 256, "Hello World!", false);
	return (0);
}
