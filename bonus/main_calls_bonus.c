/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:32:30 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/30 04:47:38 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	ft_create_window(mlx);
	ft_img_init(mlx);
	ft_render(mlx);
	mlx->move_count = 0;
	mlx_key_hook(mlx->win_ptr, ft_input, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_close_window, mlx);
	mlx->p_lives = 3;
	ft_printf("Total lives: %i\n", mlx->p_lives);
	ft_user_interface(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	ft_comp_map(t_mlx *mlx)
{
	ft_make_matrix(mlx);
	if (!ft_comp_map_count_elements(mlx))
		return (0);
	if (!ft_comp_map_elements(mlx))
		return (0);
	if (!ft_comp_map_rectangle(mlx))
		return (0);
	if (!ft_comp_map_surrounded(mlx))
		return (0);
	mlx->flood_filled_map = ft_matrixdup(mlx->playable_map);
	ft_comp_map_flood_fill(mlx->flood_filled_map, "P1N");
	if (!ft_comp_map_beateable(mlx))
	{
		return (ft_free_matrix(mlx->flood_filled_map),
			ft_free_matrix(mlx->playable_map), 0);
	}
	ft_free_matrix(mlx->flood_filled_map);
	return (1);
}

int	ft_comp_map_route(int argc, char **argv, t_mlx *mlx)
{
	size_t	len;

	if (argc != 2)
		return (ft_printf_error(ERROR_INVALID_ARGS), 0);
	len = ft_strlen(argv[1]);
	if (len <= ft_strlen("maps/.ber"))
		return (ft_printf_error(ERROR_NAME), 0);
	if (ft_strncmp(argv[1] + len - 4, ".ber", -1) != 0)
		return (ft_printf_error(ERROR_BER), 0);
	mlx->fd = open(argv[1], O_RDONLY);
	if (mlx->fd == -1)
		return (ft_printf_error(ERROR_FD), 0);
	return (1);
}
