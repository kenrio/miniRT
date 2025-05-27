/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/22 09:23:56 by tishihar         ###   ########.fr       */
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


// t_min, t_max: distance camera to obj
//  --- macro ---
// # define WIN_W 4096
// # define WIN_H 2048
# define WIN_W 2048
# define WIN_H 1024



# define PIE 3.14159265358979
# define T_MIN  1e-4
# define T_MAX  INFINITY
# define BG_COLOR 0x000000

#define SPP 4            // Samples Per Pixel
#define SQRT_SPP 2       // √SPP

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

// --- utils ---
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_pos3
{
	double	x;
	double	y;
	double	z;
}	t_pos3;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

typedef struct s_ray
{
	t_pos3	origin;
	t_vec3	direction;
}	t_ray;

// t   : distance of camera to obj
// pos : hit_point
// n   : normal vector
// rgb : hit point color
typedef struct s_hit
{
	double	t;
	t_pos3	pos;
	t_vec3	n;
	t_rgb3	rgb;
}	t_hit;

// --- elements ---
typedef enum e_elem
{
	E_AMBIENT,
	E_CAMERA,
	E_LIGHT,
	E_SPHERE,
	E_PLANE,
	E_CYLINDER,
	E_INVALID,
	E_SPACE,
}	t_elem;

typedef struct s_amb
{
	double	intensity;
	t_rgb3	rgb;
	bool	is_register;
}	t_amb;

typedef struct s_light
{
	t_pos3	pos;
	double	intensity;
	t_rgb3	rgb;
}	t_light;


// pos     – camera position (ray origin)
// forward – unit vector pointing straight ahead from the camera
// right   – unit vector pointing to the camera’s right
// up      – unit vector pointing upward from the camera
// fov     – vertical field-of-view in degrees
// aspect  – viewport aspect ratio (width / height)
// half_w  – half of the viewport’s width in world units
// half_h  – half of the viewport’s height in world units
// llc     – world-space coordinates of the viewport’s lower-left corner
typedef struct s_cam
{
	t_pos3	pos;
	t_vec3	forward;
	double	fov;
	t_vec3	right;
	t_vec3	up;
	double	fov_rad;
	double	aspect;
	double	half_w;
	double	half_h;
	t_pos3	llc;
	bool	is_register;
}	t_cam;

typedef struct s_light_node
{
	t_light					value;
	struct s_light_node		*next;
}	t_light_node;



// --- objs ---

typedef struct s_sphere
{
	t_pos3	pos;
	double	diameter;
	t_rgb3	rgb;
}	t_sphere;

typedef struct s_plane
{
	t_pos3	pos;
	t_vec3	vec;
	t_rgb3	rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_pos3	pos;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_rgb3	rgb;
}	t_cylinder;

typedef	enum e_obj_kind
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_obj_kind;

typedef union u_shape
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
}	t_shape;

typedef struct s_obj
{
	t_obj_kind		kind;
	t_shape			data;
	struct s_obj	*next;
}	t_obj;


// --- math ---
typedef struct s_quad_eq
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
}	t_quad_eq;


// --- info ---
typedef struct s_info
{
	t_amb			amb;
	t_cam			cam;
	t_light_node	*lights;
	t_obj			*objs;
	bool			is_init_success;
	t_mlx			mlx;
}	t_info;





// ---functions---
// init
bool			init_info(t_info *info, char *file_name);
void			clean_info(t_info *info);
bool			init_elements(t_info *info, char *file_name);
void			init_amb(t_info *info, char *elem);
void			init_cam(t_info *info, char *elem);
void			init_lights(t_info *info, char *elem);
void			init_objs(t_info *info, char *elem, t_elem type);

// init_utils
double			parse_double(char *token);
int				parse_3int(char *token, int idx);
double			parse_3double(char *token, int idx);
t_pos3			parse_pos3(char *token);
t_vec3			parse_vec3(char *token);
t_rgb3			parse_rgb3(char *token);
t_light_node	*new_light_node(t_pos3 pos, double intensity, t_rgb3 rgb);
void			clean_light_nodes(t_light_node *head_node);
t_obj			*add_obj_front(t_obj *head, t_obj *new);
void			clean_obj_nodes(t_obj *head);
t_obj			*new_obj_sp(t_sphere sp);
t_obj			*new_obj_pl(t_plane pl);
t_obj			*new_obj_cy(t_cylinder cy);

// token
char			*get_valid_token(char *elem, int idx);

// rendering
void			render_scene(t_info *info);
t_ray			make_ray(t_cam *c, double u, double v);
t_pos3			ray_at(t_ray *ray, double distance);
unsigned int	rgb_to_uint(t_rgb3 color);
bool			intersect_sphere(t_ray *r, t_obj *o, t_hit *rec, double t_max);
bool			intersect_plane(t_ray *r, t_obj *o, t_hit *rec, double t_max);
bool			intersect_cylinder(t_ray *r, t_obj *o, t_hit *rec, double t_max);
bool			hit_scene(t_ray *r, t_obj *o, t_hit *rec);
t_rgb3			apply_light(t_rgb3 color, double intensity, double dot_nl);

// calc_light
t_rgb3			calculate_lighting(t_info *info, t_hit *rec);
t_rgb3			apply_specular(t_vec3 v, t_vec3 l, t_vec3 n, double l_intensity);

// validate
bool			is_valid_start(char c);
bool			validate_rgb(t_rgb3	rgb);
bool			validate_unit(double n);
bool			validate_unit_range(double n);
bool			validate_rad(double n);

// mlx
bool			init_mlx(t_mlx *m, int win_w, int win_h, char *win_title);
void			mlx_cleanup(t_mlx *m);
void			mlx_handle_hook(t_info *info);
void			put_pixel(int x, int y, unsigned int color, t_img *img);

// math
t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
t_vec3			vec_scale(t_vec3 v, double k);
t_vec3			vec_div(t_vec3 v, double k);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_cross(t_vec3 a, t_vec3 b);
double			vec_len(t_vec3 v);
double			vec_len2(t_vec3 v);
t_vec3			vec_normalize(t_vec3 v);
t_vec3			pos_sub(t_pos3 p1, t_pos3 p2);
double			distance_pos_to_pos(t_pos3 a, t_pos3 b);
t_pos3			pos_sub_vec(t_pos3 p, t_vec3 v);
t_pos3			pos_add_vec(t_pos3 p, t_vec3 v);

double			calc_quad_discriminant(t_quad_eq *q);
void			solve_quad_eq(t_quad_eq *q);
t_vec3			calc_right_vec(t_vec3 forward);
t_vec3			calc_up_vec(t_vec3 right, t_vec3 forward);
t_vec3			vec_reject(t_vec3 v, t_vec3 axis_unit);
t_vec3			vec_reflection(t_vec3 v, t_vec3 n);

t_rgb3		add_rgb(t_rgb3 c1, t_rgb3 c2);

// utils
char			*get_next_line(int fd);
double			ft_atof(char *str);
t_pos3			calc_llc(t_cam *cam);

// debug
void			print_info(const t_info *info);

#endif
