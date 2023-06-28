/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_calls_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:55:50 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/29 00:11:24 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_overlap(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == 'o')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_e,
					j * IMG_WIDTH, i * IMG_HEIGHT);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_p,
					j * IMG_WIDTH, i * IMG_HEIGHT);
				mlx->p_y = i;
				mlx->p_x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_render_enemy(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == 'N')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_n,
					j * IMG_WIDTH, i * IMG_HEIGHT);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
