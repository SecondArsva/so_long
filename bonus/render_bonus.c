/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:49:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/29 00:51:10 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_render(t_mlx *mlx)
{
	ft_render_floor(mlx);
	ft_render_wall(mlx);
	ft_render_collectable(mlx);
	ft_render_exit(mlx);
	ft_render_player(mlx);
	ft_render_overlap(mlx);
	ft_render_enemy(mlx);
}
