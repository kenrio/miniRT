/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:46:59 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 21:47:31 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_rgb3(const char *label, t_rgb3 c)
{
	printf("%s: r = %d, g = %d, b = %d\n", label, c.r, c.g, c.b);
}

static void	print_pos3(const char *label, t_pos3 p)
{
	printf("%s: x = %.6f, y = %.6f, z = %.6f\n", label, p.x, p.y, p.z);
}

static void	print_vec3(const char *label, t_vec3 v)
{
	printf("%s: x = %.6f, y = %.6f, z = %.6f\n", label, v.x, v.y, v.z);
}

static void	print_amb(const t_amb *amb)
{
	printf("=== Ambient ===\n");
	printf("intensity: %.6f\n", amb->intensity);
	print_rgb3("rgb", amb->rgb);
}

static void	print_cam(const t_cam *cam)
{
	printf("\n=== Camera ===\n");
	print_pos3("pos", cam->pos);
	print_vec3("forward", cam->forward);
	print_vec3("right", cam->right);
	print_vec3("up", cam->up);
	printf("fov: %.6f\n", cam->fov);
	printf("aspect: %.6f\n", cam->aspect);
	printf("half_w: %.6f\n", cam->half_w);
	printf("half_h: %.6f\n", cam->half_h);
	print_pos3("llc", cam->llc);
}

static void	print_light(const t_light *light)
{
	printf("\n=== Light ===\n");
	print_pos3("pos", light->pos);
	printf("intensity: %.6f\n", light->intensity);
	print_rgb3("rgb", light->rgb);
}

static void	print_mlx(const t_mlx *mlx)
{
	printf("\n=== MiniLibX ===\n");
	printf("mlx.ptr : %p\nmlx.win : %p\n", mlx->ptr, mlx->win);
	printf("img.ptr : %p\n", mlx->img.ptr);
	printf("img.addr: %p\nbpp     : %d\nline_len: %d\nendian  : %d\n",
		mlx->img.addr, mlx->img.bpp,
		mlx->img.line_len, mlx->img.endian);
}

void	print_info(const t_info *info)
{
	if (!info)
		return ;
	print_amb(&info->amb);
	print_cam(&info->cam);
	print_light(&info->light);
	print_mlx(&info->mlx);
}
