/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_calls_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:53:05 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 07:04:27 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_player(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == 'P')
			{
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

void	ft_render_exit(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_e,
					j * IMG_WIDTH, i * IMG_HEIGHT);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_render_collectable(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_c,
					j * IMG_WIDTH, i * IMG_HEIGHT);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_render_wall(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if (mlx->playable_map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_1,
					j * IMG_WIDTH, i * IMG_HEIGHT);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_render_floor(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_0,
				j * IMG_WIDTH, i * IMG_HEIGHT);
			j++;
		}
		j = 0;
		i++;
	}
}
