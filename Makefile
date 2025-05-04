# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/04 21:35:41 by keishii          ###   ########.fr        #
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
				mlx_setup.c \
				mlx_cleanup.c \
				check_key_input.c \
				close_window.c \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS

UNAME				:= $(shell uname)

MLX_DIR				:= minilibx
LIBMLX				:= $(MLX_DIR)/libmlx.a

ifeq ($(UNAME), Darwin)
	BREW_PREFIX		:= $(shell brew --prefix)
	X11_LIB_DIRS	:= \
					-L$(BREW_PREFIX)/opt/libx11/lib \
					-L$(BREW_PREFIX)/opt/libxext/lib \
					-L$(BREW_PREFIX)/opt/libbsd/lib
	X11_INC_DIRS	:= \
					-I$(BREW_PREFIX)/opt/libx11/include \
					-I$(BREW_PREFIX)/opt/libxext/include \
					-I$(BREW_PREFIX)/opt/libbsd/include
	LFLAGS			:= -L$(MLX_DIR) -lmlx $(X11_LIB_DIRS) -lXext -lX11 -lbsd -lm
else
	LFLAGS			:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif


# **************************************************************************** #
# INCLUDES


INC_DIR			:= includes
INCLUDES		:= -I$(INC_DIR) -I$(MLX_DIR)
ifeq ($(UNAME), Darwin)
	INCLUDES	+= $(X11_INC_DIRS)
endif


# **************************************************************************** #
# RULES


all: $(NAME)

$(NAME): $(OBJ) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LFLAGS)

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

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
