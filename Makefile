# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 13:38:18 by keishii           #+#    #+#              #
#    Updated: 2025/05/19 13:11:53 by tishihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES


NAME			:= miniRT

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -O3

SRC_DIR			:= src
OBJ_DIR			:= obj


# **************************************************************************** #
# SOURCES


MLX_SRC			:= \
				mlx_hook.c \
				mlx_init.c \
				mlx_utils.c \
				mlx_put_pixel.c \

INIT_SRC		:= \
				elements_token.c \
				init_element1.c \
				init_element2.c \
				init_elements.c \
				init_info.c \
				list_light.c \
				list_obj.c \
				set_utils_ver3.c \
				set_utils.c \
				validate.c \

MATH_SRC		:= \
				vector.c \
				vector2.c \
				pos_add_vec.c \
				pos_sub_vec.c \
				pos.c \
				quadratic_eq.c \
				calc_vec_reject.c \

UTILS_SRC		:= \
				calc_screen.c \
				ft_atof.c \
				get_next_line.c \

TEST_SRC		:= \
				print_info.c \

RENDER_SRC		:= \
				ray.c \
				render_scene.c \
				render_scene_high.c \
				intersect.c \
				intersect_cy.c \
				render_utils.c \


SRC				:= \
				main.c \
				$(addprefix mlx_series/, $(MLX_SRC)) \
				$(addprefix init/, $(INIT_SRC)) \
				$(addprefix math_original/, $(MATH_SRC)) \
				$(addprefix utils/, $(UTILS_SRC)) \
				$(addprefix test/, $(TEST_SRC)) \
				$(addprefix render/, $(RENDER_SRC)) \

OBJ				:= \
				$(addprefix $(OBJ_DIR)/, \
				$(SRC:.c=.o))


# **************************************************************************** #
# LIBRARIES & FRAMEWORKS


LIBFT_DIR			:= libft
LIBFT				:= ${LIBFT_DIR}/libft.a

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
