/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_high.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:31:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 17:30:27 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static t_rgb3	sample_pixel(t_info *info, int x, int y);
// static double	delta(void);

// void	render_scene(t_info *info)
// {
// 	int		x;
// 	int		y;
// 	t_rgb3	avg;

// 	y = 0;
// 	while (y < WIN_H)
// 	{
// 		x = 0;
// 		while (x < WIN_W)
// 		{
// 			avg = sample_pixel(info, x, y);
// 			put_pixel(x, y, rgb_to_uint(avg), &info->mlx.img);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static t_rgb3	sample_pixel(t_info *info, int x, int y)
// {
// 	int		sx;
// 	int		sy;
// 	t_rgb3	sum;
// 	double	inv;
// 	t_hit	rec;

// 	inv = 1.0 / SPP;
// 	sum = (t_rgb3){0, 0, 0};
// 	sy = 0;
// 	while (sy < SQRT_SPP)
// 	{
// 		sx = 0;
// 		while (sx < SQRT_SPP)
// 		{
// 			double	rx = ((double)sx + 0.5 + delta()) / SQRT_SPP;
// 			double	ry = ((double)sy + 0.5 + delta()) / SQRT_SPP;
// 			double	u = (x + rx) / (WIN_W - 1);
// 			double	v = 1.0 - (y + ry) / (WIN_H - 1);
// 			t_ray	ray = make_ray(&info->cam, u, v);
// 			if (hit_scene(&ray, info->objs, &rec) == true)
// 				sum = add_rgb_simple(sum,
// 						calculate_lighting(info, &rec, &ray, 0));
// 			else
// 				sum = add_rgb_simple(sum, uint_to_rgb(BG_COLOR));
// 			sx++;
// 		}
// 		sy++;
// 	}
// 	sum.r *= inv;
// 	sum.g *= inv;
// 	sum.b *= inv;
// 	return (sum);
// }

// static double	delta(void)
// {
// 	return (((double)rand() / RAND_MAX - 0.5) * 0.3);
// }
