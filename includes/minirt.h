/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/09 18:32:14 by keishii          ###   ########.fr       */
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


//  --- macro ---
# define WIN_W 1024
# define WIN_H 1024
# define ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//  --- structure ---
// mlx
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

// utils
typedef struct s_vec3
{
    double    x;
    double    y;
    double    z;
}    t_vec3;

typedef t_vec3 t_pos3;

// typedef struct s_pos3
// {
// 	double    x;
//     double    y;
//     double    z;
// }	t_pos3;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

// info
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

typedef struct s_info
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_mlx	mlx;
}	t_info;

// ---functions---
// init
bool	init_project(t_info *info, char *file_name);
void	destroy_project(t_info *info);
bool	set_info(t_info *info, char *file_name);

// mlx
bool	mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title);
void	mlx_cleanup(t_mlx *m);
void	mlx_handle_hook(t_info *info);

// utils
char	*get_next_line(int fd);

// render functions
void	cam_setup(t_cam *c);
t_ray	make_ray(t_cam *c, double u, double v);
bool	hit_sphere(t_ray r, t_vec3 center, double radius);
void	render_scene(t_img *img, t_cam *cam);

// vector calculation
t_vec3	v_add(t_vec3 a, t_vec3 b);
t_vec3	v_sub(t_vec3 a, t_vec3 b);
t_vec3	v_scale(t_vec3 v, double k);
double	v_dot(t_vec3 a, t_vec3 b);
t_vec3	v_cross(t_vec3 a, t_vec3 b);
double	v_len(t_vec3 v);
t_vec3	v_norm(t_vec3 v);

#endif
