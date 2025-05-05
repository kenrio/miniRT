# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/05 22:02:39 by keishii          ###   ########.fr        #
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


SRC_VEC			:= \
				v_add.c \
				v_sub.c \
				v_scale.c \
				v_dot.c \
				v_cross.c \
				v_len.c \
				v_norm.c \

SRC_RENDER		:= \
				cam_setup.c \
				make_ray.c \
				render_scene.c \
				hit_sphere.c \

SRC				:= \
				main.c \
				mlx_setup.c \
				mlx_cleanup.c \
				check_key_input.c \
				close_window.c \
				$(addprefix vector/, $(SRC_VEC)) \
				$(addprefix render/, $(SRC_RENDER)) \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS


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
INCLUDES			:= -I$(INC_DIR) -I$(MLX_DIR)

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
