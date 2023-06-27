/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:49:27 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 07:02:02 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render(t_mlx *mlx)
{
	ft_render_floor(mlx);
	ft_render_wall(mlx);
	ft_render_collectable(mlx);
	ft_render_exit(mlx);
	ft_render_player(mlx);
	ft_render_overlap(mlx);
}
