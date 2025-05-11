# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/11 11:35:49 by keishii          ###   ########.fr        #
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
				intersect_sphere.c \
				pos_sub.c \
				pos_sub_vec.c \
				pos_add_vec.c \
				print_cam_info.c \



SRC				:= \
				main.c \
				$(addprefix mlx_series/, $(MLX_SRC)) \
				$(addprefix init/, $(INIT_SRC)) \
				$(addprefix utils/, $(UTILS_SRC)) \
				$(addprefix vector/, $(SRC_VEC)) \
				$(addprefix render/, $(SRC_RENDER)) \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS

LIBFT_DIR		:= libft
LIBFT			:= ${LIBFT_DIR}/libft.a

MLX_DIR				:= minilibx
MLX_LIB				:= $(MLX_DIR)/libmlx.a

LFLAGS				:= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lbsd -lm

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

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LFLAGS)

$(MLX_LIB):
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
