/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map_calls_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 06:35:55 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 07:09:38 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_comp_map_surrounded(t_mlx *mlx)
{
	size_t	i;
	size_t	j;
	size_t	last_row;
	size_t	last_col;

	i = 0;
	j = 0;
	last_row = mlx->map_len_y - 1;
	last_col = mlx->map_len_x - 1;
	while (mlx->playable_map[i])
	{
		while (mlx->playable_map[i][j])
		{
			if ((mlx->playable_map[0][j] != '1')
				|| (mlx->playable_map[i][0] != '1')
				|| (mlx->playable_map[i][last_col] != '1')
				|| (mlx->playable_map[last_row][j] != '1'))
				return (ft_printf_error(ERROR_SORROUNDED), 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (ft_printf("[v] El mapa está rodeado por muros\n"), 1);
}

int	ft_comp_map_rectangle(t_mlx *mlx)
{
	size_t	size_ref;
	size_t	comp_val;
	size_t	axis_y;
	size_t	i;

	size_ref = ft_strlen(mlx->playable_map[0]);
	axis_y = mlx->map_len_y;
	i = 0;
	while (axis_y-- > 0)
	{
		comp_val = ft_strlen(mlx->playable_map[i]);
		if (comp_val != size_ref)
			return (ft_printf_error(ERROR_RECTANGLE), 0);
		i++;
	}
	mlx->map_len_x = size_ref;
	return (ft_printf("[v] El mapa es rectangular.\n"), 1);
}

int	ft_comp_map_elements(t_mlx *mlx)
{
	if (mlx->count_c < 1)
		return (ft_printf_error(ERROR_NO_C), 0);
	if (mlx->count_e < 1)
		return (ft_printf_error(ERROR_NO_E), 0);
	if (mlx->count_e > 1)
		return (ft_printf_error(ERROR_A_LOT_E), 0);
	if (mlx->count_p < 1)
		return (ft_printf_error(ERROR_NO_P), 0);
	if (mlx->count_p > 1)
		return (ft_printf_error(ERROR_A_LOT_P), 0);
	return (ft_printf("[v] El mapa tiene los elementos requeridos.\n"), 1);
}

int	ft_comp_map_count_elements(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	mlx->count_c = 0;
	mlx->count_e = 0;
	mlx->count_p = 0;
	while (mlx->playable_map[i++])
	{
		while (mlx->playable_map[i][j])
		{
			if (!ft_strchr("01CEP", mlx->playable_map[i][j]))
				return (ft_printf_error(ERROR_INVALID_CHARS), 0);
			if (mlx->playable_map[i][j] == 'C')
				mlx->count_c++;
			else if (mlx->playable_map[i][j] == 'E')
				mlx->count_e++;
			else if (mlx->playable_map[i][j] == 'P')
				mlx->count_p++;
			j++;
		}
		j = 0;
	}
	return (1);
}

void	ft_make_matrix(t_mlx *mlx)
{
	char	*single_line;
	char	*map_line;
	char	*aux_ref;

	single_line = get_next_line(mlx->fd);
	map_line = ft_calloc(1, sizeof(char));
	mlx->map_len_y = 0;
	while (single_line)
	{
		aux_ref = map_line;
		map_line = ft_strjoin(map_line, single_line);
		free(aux_ref);
		free(single_line);
		mlx->map_len_y++;
		single_line = get_next_line(mlx->fd);
		if (single_line == NULL)
			break ;
	}
	free(single_line);
	mlx->playable_map = ft_split(map_line, '\n');
	if (!mlx->playable_map)
		ft_free_matrix(mlx->playable_map);
	free(map_line);
}
