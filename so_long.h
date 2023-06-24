/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:47 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/24 22:37:07 by davidga2         ###   ########.fr       */
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
