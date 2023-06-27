# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 14:06:19 by davidga2          #+#    #+#              #
#    Updated: 2023/06/28 00:13:42 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

NAME = so_long
SRC = src/comp_map_calls_0.c 	\
	  src/comp_map_calls_1.c 	\
	  src/input_calls.c 		\
	  src/main.c 				\
	  src/main_calls.c 			\
	  src/mlx_calls.c 			\
	  src/render.c 				\
	  src/render_calls_0.c 		\
	  src/render_calls_1.c
OBJS = $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

### RULES ###

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(MLX_MAC) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
	$(MAKE) re -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus
