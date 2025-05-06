# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/06 15:50:03 by tishihar         ###   ########.fr        #
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

MLX_SRC			:= \
				mlx_hook.c \
				mlx_setup.c \
				mlx_utils.c \

INIT_SRC			:= \
				project_init.c \
				info_init.c \

UTILS_SRC			:= \
				get_next_line.c \


SRC				:= \
				main.c \
				$(addprefix mlx_series/, $(MLX_SRC)) \
				$(addprefix init/, $(INIT_SRC)) \
				$(addprefix init/, $(UTILS_SRC)) \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS

LIBFT_DIR		:= libft
LIBFT_INC_DIR	:= $(LIBFT_DIR)
LIBFT			:= ${LIBFT_DIR}/libft.a

MLX_DIR				:= minilibx
LIBMLX				:= $(MLX_DIR)/libmlx.a

LFLAGS				:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm

UNAME				:= $(shell uname)

ifeq ($(UNAME), Darwin)
	BREW_PREFIX		:= $(shell brew --prefix)
	X11_LIB_DIRS	:= \
					-L$(BREW_PREFIX)/opt/libx11/lib \
					-L$(BREW_PREFIX)/opt/libxext/lib \
					-L$(BREW_PREFIX)/opt/libbsd/lib

	LFLAGS			+= $(X11_LIB_DIRS)
endif


# **************************************************************************** #
# INCLUDES


INC_DIR				:= includes
INCLUDES			:= -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

ifeq ($(UNAME), Darwin)
	X11_INC_DIRS	:= \
					-I$(BREW_PREFIX)/opt/libx11/include \
					-I$(BREW_PREFIX)/opt/libxext/include \
					-I$(BREW_PREFIX)/opt/libbsd/include

	INCLUDES		+= $(X11_INC_DIRS)
endif


# **************************************************************************** #
# RULES


all: $(NAME)

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LFLAGS)

$(LIBMLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	${MAKE} -C ${LIBFT_DIR}	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	${MAKE} -C ${LIBFT_DIR} fclean

fclean: clean
	rm -f $(NAME)

re: fclean all


# **************************************************************************** #
# PHONY


.PHONY: all clean fclean re
