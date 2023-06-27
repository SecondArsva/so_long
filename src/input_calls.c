/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_calls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:56:51 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 19:09:41 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_print_total_moves(t_mlx *mlx)
{
	mlx->move_count++;
	ft_printf("Total moves: %i\n", mlx->move_count);
}

void	ft_move_who_am_i(t_mlx *mlx, int mod_y, int mod_x)
{
	if (mlx->playable_map[mlx->p_y][mlx->p_x] == 'P')
	{
		mlx->playable_map[mlx->p_y][mlx->p_x] = '0';
		mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] = 'P';
	}
	else if (mlx->playable_map[mlx->p_y][mlx->p_x] == 'o')
	{
		mlx->playable_map[mlx->p_y][mlx->p_x] = 'E';
		mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] = 'P';
	}
}

void	ft_move_to_element(t_mlx *mlx, int mod_y, int mod_x)
{
	if (mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] == 'C')
		mlx->count_c--;
	else if (mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] == 'E')
	{
		if (mlx->count_c == 0)
		{
			ft_move_print_total_moves(mlx);
			exit(0);
		}
		mlx->playable_map[mlx->p_y][mlx->p_x] = '0';
		mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] = 'o';
	}
}

void	ft_move(t_mlx *mlx, int mod_y, int mod_x)
{
	if (mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] != '1')
	{
		ft_move_to_element(mlx, mod_y, mod_x);
		ft_move_who_am_i(mlx, mod_y, mod_x);
		ft_move_print_total_moves(mlx);
		ft_render(mlx);
	}
}
