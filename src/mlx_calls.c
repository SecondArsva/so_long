/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:45:34 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 07:08:03 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_FAILURE);
}

int	ft_input(int keycode, t_mlx *mlx)
{
	if (keycode == W || keycode == UP)
		ft_move(mlx, -1, 0);
	else if (keycode == S || keycode == DOWN)
		ft_move(mlx, 1, 0);
	else if (keycode == A || keycode == LEFT)
		ft_move(mlx, 0, -1);
	else if (keycode == D || keycode == RIGHT)
		ft_move(mlx, 0, 1);
	ft_render(mlx);
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	ft_img_init(t_mlx *mlx)
{
	mlx->img_width = IMG_WIDTH;
	mlx->img_height = IMG_HEIGHT;
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			IMG_0, &mlx->img_width, &mlx->img_height);
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			IMG_1, &mlx->img_width, &mlx->img_height);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr,
			IMG_C, &mlx->img_width, &mlx->img_height);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr,
			IMG_E, &mlx->img_width, &mlx->img_height);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr,
			IMG_P, &mlx->img_width, &mlx->img_height);
	if ((!mlx->img_0) || (!mlx->img_1) || (!mlx->img_c)
		|| (!mlx->img_e) || (!mlx->img_p))
		return (ft_printf_error(ERROR_IMG_PTR), 0);
	return (1);
}

int	ft_create_window(t_mlx *mlx)
{
	mlx->win_x = mlx->map_len_x * IMG_WIDTH;
	mlx->win_y = mlx->map_len_y * IMG_HEIGHT;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			mlx->win_x, mlx->win_y, WIN_TITLE);
	if (!mlx->win_ptr)
		return (ft_printf_error(ERROR_WIN_PTR), 0);
	return (1);
}
