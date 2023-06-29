/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:47 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/29 03:38:27 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>

# ifndef MAX_PATH_LENGTH
#  define MAX_PATH_LENGTH 256
# endif

# define IMG_WIDTH 16
# define IMG_HEIGHT 32
# define WIN_TITLE "American History X: The Game"
# define IMG_0 "textures/empty.xpm"
# define IMG_1 "textures/wall.xpm"
# define IMG_C "textures/collectable.xpm"
# define IMG_E "textures/exit.xpm"
# define IMG_PU "textures/player_up.xpm"
# define IMG_P "textures/player_down.xpm"
# define IMG_PL "textures/player_left.xpm"
# define IMG_PR "textures/player_right.xpm"
# define IMG_N "textures/enemy.xpm"

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
	void	*img_n;
	int		p_lives;
}			t_mlx;

int		main(int argc, char *argv[]);
int		ft_comp_map(t_mlx *mlx);
int		ft_comp_map_route(int argc, char **argv, t_mlx *mlx);
void	ft_make_matrix(t_mlx *mlx);
int		ft_comp_map_count_elements(t_mlx *mlx);
int		ft_comp_map_elements(t_mlx *mlx);
int		ft_comp_map_rectangle(t_mlx *mlx);
int		ft_comp_map_surrounded(t_mlx *mlx);
void	ft_comp_map_flood_fill(char **matrix, char *str);
void	ft_flood_fill_if(char **matrix, char *str, size_t i, size_t j);
int		ft_comp_map_beateable(t_mlx *mlx);
int		ft_mlx(t_mlx *mlx);
int		ft_create_window(t_mlx *mlx);
int		ft_img_init(t_mlx *mlx);
void	ft_render(t_mlx *mlx);
void	ft_render_floor(t_mlx *mlx);
void	ft_render_wall(t_mlx *mlx);
void	ft_render_collectable(t_mlx *mlx);
void	ft_render_exit(t_mlx *mlx);
void	ft_render_player(t_mlx *mlx);
void	ft_render_overlap(t_mlx *mlx);
int		ft_input(int keycode, t_mlx *mlx);
void	ft_move(t_mlx *mlx, int mod_y, int mod_x);
void	ft_move_to_element(t_mlx *mlx, int mod_y, int mod_x);
void	ft_move_who_am_i(t_mlx *mlx, int mod_y, int mod_x);
void	ft_move_print_total_moves(t_mlx *mlx);
int		ft_close_window(t_mlx *mlx);

void	ft_render_enemy(t_mlx *mlx);
#endif
