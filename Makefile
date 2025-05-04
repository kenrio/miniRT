# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/04 14:40:30 by keishii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES


NAME			:= miniRT

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror

SRC_DIR			:= src
OBJ_DIR			:= obj


# **************************************************************************** #
# SOURCES


SRC				:= \
				main.c \
				check_key_input.c \
				close_window.c \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS


MLX_DIR			:= minilibx

LFLAGS			:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd


# **************************************************************************** #
# INCLUDES


INC_DIR			:= includes
INCLUDES		:= -I$(INC_DIR) -I$(MLX_DIR)


# **************************************************************************** #
# RULES


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)/
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all


# **************************************************************************** #
# PHONY


.PHONY: all clean fclean re
