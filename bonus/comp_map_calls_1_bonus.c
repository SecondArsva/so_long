/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map_calls_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:40:53 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/29 06:39:09 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_comp_map_beateable(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->flood_filled_map[i])
	{
		while (mlx->flood_filled_map[i][j])
		{
			if (mlx->flood_filled_map[i][j] == 'E')
				return (ft_printf_error(ERROR_REACH_E), 0);
			else if (mlx->flood_filled_map[i][j] == 'C')
				return (ft_printf_error(ERROR_REACH_C), 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_flood_fill_if(char **matrix, char *str, size_t i, size_t j)
{
	if (!ft_strchr(str, matrix[i - 1][j]))
	{
		matrix[i - 1][j] = str[0];
		ft_flood_fill_if(matrix, str, i - 1, j);
	}
	if (!ft_strchr(str, matrix[i + 1][j]))
	{
		matrix[i + 1][j] = str[0];
		ft_flood_fill_if(matrix, str, i + 1, j);
	}
	if (!ft_strchr(str, matrix[i][j - 1]))
	{
		matrix[i][j - 1] = str[0];
		ft_flood_fill_if(matrix, str, i, j - 1);
	}
	if (!ft_strchr(str, matrix[i][j + 1]))
	{
		matrix[i][j + 1] = str[0];
		ft_flood_fill_if(matrix, str, i, j + 1);
	}
}

void	ft_comp_map_flood_fill(char **matrix, char *str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				ft_flood_fill_if(matrix, str, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_empty_line(char *str)
{
	if (str[0] == '\n')
	{
		ft_printf_error(ERROR_EMPTY_LINE);
		exit(0);
	}
}
