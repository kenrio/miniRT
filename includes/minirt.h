/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/12 15:01:04 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

// --- memo ---
// world_up vector define (x, y, z) = (0, 0, 1)
// in calc_screen_vec.c

//  --- macro ---
# define WIN_W 1024
# define WIN_H 1024
# define ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//  --- structure ---
// --- mlx ---
typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

// --- element ---
typedef struct s_vec3
{
    double    x;
    double    y;
    double    z;
}    t_vec3;

typedef struct s_pos3
{
	double    x;
    double    y;
    double    z;
}	t_pos3;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

// --- info elem ---
typedef enum e_elem {
    E_AMBIENT,
	E_CAMERA,
	E_LIGHT,
    E_SPHERE, 
	E_PLANE, 
	E_CYLINDER,
    E_INVALID,
	E_SPACE,
}   t_elem;

typedef struct s_amb
{
	double	intensity;
	t_rgb3	rgb;
}	t_amb;

typedef	struct s_light
{
	t_pos3	pos;
	double	intensity;
	t_rgb3	rgb;
}	t_light;

/*
// pos     – camera position (ray origin)
// forward – unit vector pointing straight ahead from the camera
// right   – unit vector pointing to the camera’s right
// up      – unit vector pointing upward from the camera
// fov     – vertical field-of-view in degrees
// aspect  – viewport aspect ratio (width / height)
// half_w  – half of the viewport’s width in world units
// half_h  – half of the viewport’s height in world units
// llc     – world-space coordinates of the viewport’s lower-left corner
*/
typedef struct s_cam
{
    t_pos3    pos;
    t_vec3    forward;
    double    fov;
    t_vec3    right;
    t_vec3    up;
    double    aspect;
    double    half_w;
    double    half_h;
    t_pos3    llc;
}    t_cam;

typedef struct s_sphere
{
	t_pos3	pos;
	double	diameter;
	t_rgb3	rgb;
}	t_sphere;

typedef	struct s_plane
{
	t_pos3	pos;
	t_vec3	vec;
	t_rgb3	rgb;
}	t_plane;

typedef	struct	s_cylinder
{
	t_pos3	pos;
	t_vec3	vec;
	double	diameter;
	double	height;
	t_rgb3	rgb;
}	t_cylinder;

// --- element node ---
typedef	struct s_light_node
{
	t_light					value;
	struct	s_light_node	*next;
}	t_light_node;

// --- element ---
typedef struct s_info
{
	t_amb			amb;
	t_cam			cam;
	t_light_node	*lights;
	t_sphere		sp;
	t_plane			pl;
	t_cylinder		cy;
	bool			is_init_success;
	t_mlx			mlx;
}	t_info;

// ---functions---
// init
bool 	init_info(t_info *info, char *file_name);
bool	init_elements(t_info *info, char *file_name);
void	init_amb(t_info *info, char *elem);
void	init_cam(t_info *info, char *elem);
void	init_light(t_info *info, char *elem);
void	init_sphere(t_info *info, char *elem);
void	init_plane(t_info *info, char *elem);
void	init_cylinder(t_info *info, char *elem);

// init_utils
double	parse_double(char *token);
int		parse_3int(char *token, int idx);
double	parse_3double(char *token, int idx);
t_pos3	parse_pos3(char *token);
t_vec3	parse_vec3(char *token);
t_rgb3	parse_rgb3(char *token);

// token
char	*get_valid_token(char *elem, int idx);

// validate
bool	is_valid_start(char c);
bool	validate_rgb(int n);
bool	validate_unit(double n);
bool	validate_unit_range(double n);
bool	validate_rad(double n);

// mlx
bool	init_mlx(t_mlx *m, int win_w, int win_h, char *win_title);
void	mlx_cleanup(t_mlx *m);
void	mlx_handle_hook(t_info *info);

// math
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
double	vec_dot(t_vec3 a, t_vec3 b);
double	vec_len(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);

// utils
char	*get_next_line(int fd);
double	ft_atof(char *str);
t_vec3	calc_right_vec(t_vec3 forward);
t_vec3	calc_up_vec(t_vec3 right, t_vec3 forward);

// debug
void	print_info(const t_info *info);

#endif
