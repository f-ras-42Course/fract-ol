

// void	key_loop_hooks(t_mlx_data *window)
// {
// 	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE)\
// 		|| mlx_is_key_down(window->mlx, MLX_KEY_Q))
// 		mlx_close_window(window->mlx);
// 	if (mlx_is_key_down(window->mlx, MLX_KEY_W)\
// 		|| mlx_is_key_down(window->mlx, MLX_KEY_UP))
// 		window->image->instances->y -= 5;
// 	if (mlx_is_key_down(window->mlx, MLX_KEY_A)\
// 		|| mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
// 		window->image->instances->x -= 5;
// 	if (mlx_is_key_down(window->mlx, MLX_KEY_S)\
// 		|| mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
// 		window->image->instances->y += 5;
// 	if (mlx_is_key_down(window->mlx, MLX_KEY_D)\
// 		|| mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
// 		window->image->instances->x += 5;
// }