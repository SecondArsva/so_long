/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:47 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/27 02:09:51 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

# ifndef MAX_PATH_LENGTH
#  define MAX_PATH_LENGTH 256
# endif

# define IMG_WIDTH 16
# define IMG_HEIGHT 32
# define WIN_TITLE "So_long"
# define IMG_0 "textures/empty.xpm"
# define IMG_1 "textures/wall.xpm"
# define IMG_C "textures/collectable.xpm"
# define IMG_E "textures/exit.xpm"
# define IMG_P "textures/player_down.xpm"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ERROR_STRUCT_RESERVE "Error\n[x] Struct reserve failed.i\n"
# define ERROR_INVALID_ARGS	"Error\n[x] Invalid number of arguments.\n"
# define ERROR_NAME "Error\n[x] The introduced map has a very short name.\n"
# define ERROR_BER "Error\n[x] The introduced map is not a '.ber'.\n"
# define ERROR_FD "Error\n[x] The file could not be opened correctly.\n"
# define ERROR_WIN_PTR "Error\n[x] Window pointer reserve failed.\n"
# define ERROR_IMG_PTR "Error\n[x] Some of the images could not be reserved.\n"
# define ERROR_INVALID_CHARS "Error\n[x] The map has invalid characters.\n"
# define ERROR_NO_C "Error\n[x] There must be at least one collectible.\n"
# define ERROR_NO_E	"Error\n[x] Need to add the exit.\n"
# define ERROR_A_LOT_E "Error\n[x] There can only be one exit.\n"
# define ERROR_NO_P "Error\n[x] Need to add the character.\n"
# define ERROR_A_LOT_P "Error\n[x] There can only be one player.\n"
# define ERROR_RECTANGLE "Error\n[x] The map is not rectangular.\n"
# define ERROR_SORROUNDED "Error\n[x] The map is not surrounded by walls.\n"
# define ERROR_REACH_E "Error\n[x] The exit cannot be reached.\n"
# define ERROR_REACH_C "Error\n[x] Cannot reach any of the collectibles.\n"

typedef struct s_mlx{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	win_x;
	size_t	win_y;
	char	*title;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	int		img_width;
	int		img_height;
	char	**playable_map;
	size_t	map_len_x;
	size_t	map_len_y;
	size_t	count_c;
	size_t	count_e;
	size_t	count_p;
	char	**flood_filled_map;
	size_t	p_x;
	size_t	p_y;
	size_t	move_count;
}			t_mlx;

#endif
