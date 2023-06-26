/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:47 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/26 10:31:38 by davidga2         ###   ########.fr       */
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

# define ERROR_STRUCT_RESERVE "Error\n[x] Struct reserve failed."
# define ERROR_INVALID_ARGS	"Error\n[x] Invalid number of arguments."
# define ERROR_MAP_NAME "Error\n[x] The introduced map has a very short name."
# define ERROR_BER "Error\n[x] The introduced map is not a '.ber'."
# define ERROR_INVALID_FD "Error\n[x] The file could not be opened correctly."
# define ERROR_WIN_PTR "Error\n[x] Window pointer reserve failed."
# define ERROR_IMG_PTR "Error\n[x] Some of the images could not be reserved."
# define ERROR_IVALID_CHAR "Error\n[x] The map has invalid characters."
# define ERROR_NO_C "Error\n[x] There must be at least one collectible."
# define ERROR_NO_E	"Error\n[x] Need to add the exit"
# define ERROR_A_LOT_E "Error\n[x] There can only be one exit."
# define ERROR_NO_P "Error\n[x] Need to add the character."
# define ERROR_A_LOT_P "Error\n[x] There can only be one player."
# define ERROR_MAP_ISNT_RECTANGLE "Error\n[x] The map is not rectangular."
# define ERROR_SORROUNDED "Error\n[x] The map is not surrounded by walls."
# define ERROR_REACH_E "Error\n[x] The exit cannot be reached."
# define ERROR_REACH_C "Error\n[x] Cannot reach any of the collectibles."

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
