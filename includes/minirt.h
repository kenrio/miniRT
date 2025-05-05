/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 22:02:12 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "mlx.h"

# define WIN_W 1024
# define WIN_H 1024

# define ESC 65307

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/*
pos: カメラ位置（レイの始点）
forward: カメラ方向（レイの進行方向？）
right: 右方向ベクトル
up: 上方向ベクトル
fov: 視野角
aspect: ウィンドウのアスペクト比
half_w: ウィンドウ幅の半分
half_h: ウィンドウ高の半分
llc (lower-left-corner): ビューボート左下の3D座標
*/
typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	double	fov;
	double	aspect;
	double	half_w;
	double	half_h;
	t_vec3	llc;
}	t_cam;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

int		mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title);
void	mlx_cleanup(t_mlx *m);
int		check_key_input(int key, t_mlx *m);
int		close_window(t_mlx *m);

/*render functions*/
void	cam_setup(t_cam *c);
t_ray	make_ray(t_cam *c, double u, double v);
bool	hit_sphere(t_ray r, t_vec3 center, double radius, double *t_out);
void	render_scene(t_mlx *m, t_cam *cam);

/*vector calculation*/
t_vec3	v_add(t_vec3 a, t_vec3 b);
t_vec3	v_sub(t_vec3 a, t_vec3 b);
t_vec3	v_scale(t_vec3 v, double k);
double	v_dot(t_vec3 a, t_vec3 b);
t_vec3	v_cross(t_vec3 a, t_vec3 b);
double	v_len(t_vec3 v);
t_vec3	v_norm(t_vec3 v);

#endif
