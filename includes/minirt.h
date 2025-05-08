/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/08 17:13:38 by tishihar         ###   ########.fr       */
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

// info
typedef enum e_elem {
    E_AMBIENT,
	E_CAMERA,
	E_LIGHT,
    E_SPHERE, 
	E_PLANE, 
	E_CYLINDER,
    E_INVALID
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

// token
char	*get_valid_token(char *elem, int idx);


// mlx
bool	mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title);
void	mlx_cleanup(t_mlx *m);
void	mlx_handle_hook(t_info *info);

// utils
char	*get_next_line(int fd);
double	ft_atof(char str);

#endif
