# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 14:06:19 by davidga2          #+#    #+#              #
#    Updated: 2023/06/27 07:21:59 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- VARIABLES ---

NAME = so_long
SRC_DIR = src
SRC = $(SRC_DIR/%.c)
OBJS = $(SRC%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = $(SRC_DIR)/so_long.h

NAME_BONUS = so_long_bonus
BONUS_DIR = bonus
SCR_BONUS = $(BONUS_DIR%bonus.c)

# --- RULES ---

all: $(NAME)

lib: $(LIBFT)

bonus: $(NAME_BONUS)

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
