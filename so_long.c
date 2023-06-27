/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:30 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 19:38:14 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// main, evidentemente. Necesario en este proyecto a ser un programa.
int			main(int argc, char *argv[]);
// Función que llama a las demás funciones de comprobación:
static int	ft_comp_map(t_mlx *mlx);
// Comprobación de la ruta del mapa introducida por argumento
// y apertura del mismo.
static int	ft_comp_map_route(int argc, char **argv, t_mlx *mlx);
// Lectura del mapa. char **map. (Leaks a full)
static void	ft_make_matrix(t_mlx *mlx);
// Cuenta los elementos importantes del  mapa. Coleccionables, salida y personaje.
static int	ft_comp_map_count_elements(t_mlx *mlx);
// Comprueba que los elementos del mapa sean los correctos.
static int	ft_comp_map_elements(t_mlx *mlx);
// Comprueba que el mapa sea rectangular. (Sí, los cuadrados también son rectángulos)
static int	ft_comp_map_rectangle(t_mlx *mlx);
// Comprueba que el mapa esté rodeado de muros.
static int	ft_comp_map_surrounded(t_mlx *mlx);
// Comprueba que el mapa sea solucionable. Flood Fill.
static void	ft_comp_map_flood_fill(char **matrix, char *str);
static void	ft_flood_fill_if(char **matrix, char *str, size_t i, size_t j);
// Tras el Flood Fill, he de verificar si se queda algún coleccionable
// o salida.
static int	ft_comp_map_beateable(t_mlx *mlx);
// Limpiamos mapa. ///////////////////////////////////////////////////////
// Establece conexión con mlx y llama a las otras funciones gráficas.
static int	ft_mlx(t_mlx *mlx);
// Crea una ventana con las proporciones correctas según el tamaño
// del mapa y los sprites.
static int	ft_create_window(t_mlx *mlx);
// Crea los punteros que albergarán cada una de las imágenes.
static int	ft_img_init(t_mlx *mlx);
// Llama a las funciones de renderizado.
static void	ft_render(t_mlx *mlx);
// Pre y renderiza el suelo con imágenes del char 0.
static void	ft_render_floor(t_mlx *mlx);
// Pre y renderiza los demás sprites en si lugar.
static void	ft_render_wall(t_mlx *mlx);
static void	ft_render_collectable(t_mlx *mlx);
static void	ft_render_exit(t_mlx *mlx);
static void	ft_render_player(t_mlx *mlx);
static void	ft_render_overlap(t_mlx *mlx);
// Funciones que reciben los inputs introducidos mediante la función mx_hook
// mediante las cuales se moverá el personaje.
static int	ft_input(int keycode, t_mlx *mlx);
static void	ft_move(t_mlx *mlx, int mod_y, int mod_x);
static void	ft_move_to_element(t_mlx *mlx, int mod_y, int mod_x);
static void	ft_move_who_am_i(t_mlx *mlx, int mod_y, int mod_x);
static void	ft_move_print_total_moves(t_mlx *mlx);
// mpizzolo me enseñó esto. Es para cerrar la ventana con la "x".
int			ft_close_window(t_mlx *mlx);

int	ft_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_FAILURE);
}

static void	ft_move_print_total_moves(t_mlx *mlx)
{
	mlx->move_count++;
	ft_printf("Total moves: %i\n", mlx->move_count);
}

static void	ft_move_to_element(t_mlx *mlx, int mod_y, int mod_x)
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

static void	ft_move_who_am_i(t_mlx *mlx, int mod_y, int mod_x)
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

static void	ft_move(t_mlx *mlx, int mod_y, int mod_x)
{
	if (mlx->playable_map[mlx->p_y + mod_y][mlx->p_x + mod_x] != '1')
	{
		ft_move_to_element(mlx, mod_y, mod_x);
		ft_move_who_am_i(mlx, mod_y, mod_x);
		ft_move_print_total_moves(mlx);
		ft_render(mlx);
	}
}

int	ft_input(int keycode, t_mlx *mlx)
{
	if (keycode == W || keycode == UP)
	{
		ft_move(mlx, -1, 0);
		ft_render(mlx);
	}
	if (keycode == S || keycode == DOWN)
	{
		ft_move(mlx, 1, 0);
		ft_render(mlx);
	}
	if (keycode == A || keycode == LEFT)
	{
		ft_move(mlx, 0, -1);
		ft_render(mlx);
	}
	if (keycode == D || keycode == RIGHT)
	{
		ft_move(mlx, 0, 1);
		ft_render(mlx);
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

static void	ft_render_overlap(t_mlx *mlx)
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

static void	ft_render_player(t_mlx *mlx)
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

static void	ft_render_exit(t_mlx *mlx)
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

static void	ft_render_collectable(t_mlx *mlx)
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

static void	ft_render_wall(t_mlx *mlx)
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

static void	ft_render_floor(t_mlx *mlx)
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

static void	ft_render(t_mlx *mlx)
{
	ft_render_floor(mlx);
	ft_render_wall(mlx);
	ft_render_collectable(mlx);
	ft_render_exit(mlx);
	ft_render_player(mlx);
	ft_render_overlap(mlx);
}

static int	ft_comp_map_beateable(t_mlx *mlx)
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
	return (ft_printf("[v] El mapa es completable.\n"), 1);
}

static void	ft_flood_fill_if(char **matrix, char *str, size_t i, size_t j)
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

static void	ft_comp_map_flood_fill(char **matrix, char *str)
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

static int	ft_comp_map_surrounded(t_mlx *mlx)
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

static int	ft_comp_map_rectangle(t_mlx *mlx)
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

static int	ft_comp_map_elements(t_mlx *mlx)
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

static int	ft_comp_map_count_elements(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	mlx->count_c = 0;
	mlx->count_e = 0;
	mlx->count_p = 0;
	while (mlx->playable_map[i])
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
		i++;
	}
	return (1);
}

static int	ft_img_init(t_mlx *mlx)
{
	mlx->img_width = IMG_WIDTH;
	mlx->img_height = IMG_HEIGHT;
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx_ptr, IMG_0, &mlx->img_width, &mlx->img_height);
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, IMG_1, &mlx->img_width, &mlx->img_height);
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr, IMG_C, &mlx->img_width, &mlx->img_height);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, IMG_E, &mlx->img_width, &mlx->img_height);
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx_ptr, IMG_P, &mlx->img_width, &mlx->img_height);
	if ((!mlx->img_0) || (!mlx->img_1) || (!mlx->img_c)
		|| (!mlx->img_e) || (!mlx->img_p))
		return (ft_printf_error(ERROR_IMG_PTR), 0);
	return (1);
}

static int	ft_create_window(t_mlx *mlx)
{
	mlx->win_x = mlx->map_len_x * IMG_WIDTH;
	mlx->win_y = mlx->map_len_y * IMG_HEIGHT;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, WIN_TITLE);
	if (!mlx->win_ptr)
		return (ft_printf_error(ERROR_WIN_PTR), 0);
	return (1);
}

static int	ft_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	ft_create_window(mlx);
	ft_img_init(mlx);
	ft_render(mlx);
	mlx->move_count = 0;
	mlx_key_hook(mlx->win_ptr, ft_input, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_close_window, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

static void	ft_make_matrix(t_mlx *mlx)
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

static int	ft_comp_map_route(int argc, char **argv, t_mlx *mlx)
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

static int	ft_comp_map(t_mlx *mlx)
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
	ft_comp_map_flood_fill(mlx->flood_filled_map, "P1");
	if (!ft_comp_map_beateable(mlx))
	{
		return (ft_free_matrix(mlx->flood_filled_map),
				ft_free_matrix(mlx->playable_map), 0);
	}
	ft_free_matrix(mlx->flood_filled_map);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

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
