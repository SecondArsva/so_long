/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 00:52:48 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/30 18:16:33 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_user_interface(t_mlx *mlx)
{
	char	*steps;
	char	*lives;

	steps = ft_itoa(mlx->move_count);
	lives = ft_itoa(mlx->p_lives);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 3, 0, 16777214,
		"Steps: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 64, 0, 16777214, steps);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		mlx->win_x - 76, mlx->win_y - 32, 16777214, "Lives: ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		mlx->win_x - 16, mlx->win_y - 32, 16777214, lives);
	free(steps);
	free(lives);
}

void	ft_respawn(t_mlx *mlx)
{
	mlx->playable_map[mlx->p_y][mlx->p_x] = '0';
	if (mlx->playable_map[mlx->e_y - 1][mlx->e_x] == '0')
		mlx->playable_map[mlx->e_y - 1][mlx->e_x] = 'P';
	else if (mlx->playable_map[mlx->e_y + 1][mlx->e_x] == '0')
		mlx->playable_map[mlx->e_y + 1][mlx->e_x] = 'P';
	else if (mlx->playable_map[mlx->e_y][mlx->e_x - 1] == '0')
		mlx->playable_map[mlx->e_y][mlx->e_x - 1] = 'P';
	else if (mlx->playable_map[mlx->e_y][mlx->e_x + 1] == '0')
		mlx->playable_map[mlx->e_y][mlx->e_x + 1] = 'P';
}
