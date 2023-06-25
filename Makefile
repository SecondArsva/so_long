# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 14:06:19 by davidga2          #+#    #+#              #
#    Updated: 2023/06/25 04:47:20 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- VARIABLES ---

NAME = so_long
SRC = so_long.c
OBJS = $(SRC%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = so_long.h

NAME_BONUS = so_long_bonus
DIR_BONUS = bonus
#SCR_BONUS = 

# --- RULES ---

all: $(NAME)

lib: $(LIBFT)

bonus: $(BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(MLX_MAC) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
	$(MAKE) re -C $(LIBFT_DIR)

.PHONY: all clean fclean re lib bonus
