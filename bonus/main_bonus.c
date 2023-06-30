/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:31:39 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/30 05:20:41 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_l()
{
	system("leaks so_long_bonus");
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	atexit(ft_l);
	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (ft_printf_error(ERROR_STRUCT_RESERVE), 0);
	if (!ft_comp_map_route(argc, argv, mlx))
		return (free(mlx), 0);
	if (!ft_comp_map(mlx))
		return (free(mlx), 0);
	ft_mlx(mlx);
	free(mlx);
	return (0);
}
