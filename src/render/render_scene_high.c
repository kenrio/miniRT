/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_high.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:31:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/19 14:52:34 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec);
// static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max);
// static t_rgb3  sample_pixel(t_info *info, int x, int y);

// void    render_scene(t_info *info)
// {
//     int  x;
//     int  y;

//     y = 0;
//     while (y < WIN_H)
//     {
//         x = 0;
//         while (x < WIN_W)
//         {
//             t_rgb3 avg = sample_pixel(info, x, y);
//             put_pixel(x, y, rgb_to_uint(avg), &info->mlx.img);
//             x++;
//         }
//         y++;
//     }
// }

// static t_rgb3  sample_pixel(t_info *info, int x, int y)
// {
//     int     sx;
//     int     sy;
//     t_rgb3  sum;
//     double  inv = 1.0 / SPP;

// 	sum = (t_rgb3){0, 0, 0};
//     sy = 0;
//     while (sy < SQRT_SPP)
//     {
//         sx = 0;
//         while (sx < SQRT_SPP)
//         {
//             double rx =
// 				((double)sx + 0.5 + delta()) / SQRT_SPP;
//             double ry =
// 				((double)sy + 0.5 + delta()) / SQRT_SPP;
//             double u = (x + rx) / (WIN_W  - 1);
//             double v = 1.0 - (y + ry) / (WIN_H - 1);
//             t_ray ray = make_ray(&info->cam, u, v);
//             t_hit rec;
//             t_rgb3 c = (hit_scene(&ray, info->objs, &rec))
//                            ? rec.rgb
//                            : (t_rgb3){0,0,0};
//             sum.r += c.r;
//             sum.g += c.g;
//             sum.b += c.b;
//             sx++;
//         }
//         sy++;
//     }
//     sum.r *= inv; sum.g *= inv; sum.b *= inv;
//     return (sum);
// }

// static double	delta()
// {
// 	return (((double)rand() / RAND_MAX - 0.5) * 0.3);
// }

// // rayとobjが衝突するかどうかを判定し、recにぶち込む関数
// static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec)
// {
// 	bool	hit_any;
// 	t_hit	temp;
// 	double	most_close_d;

// 	hit_any = false;
// 	most_close_d = T_MAX;
// 	while (o)
// 	{
// 		if (hit_obj(r, o, &temp, most_close_d) == true)
// 		{
// 			hit_any = true;
// 			most_close_d = temp.t;
// 			*rec = temp;
// 		}
// 		o = o->next;
// 	}
// 	return (hit_any);
// }

// static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max)
// {
// 	if (o->kind == OBJ_SPHERE)
// 		return (intersect_sphere(r, o, rec, t_max));
// 	else if (o->kind == OBJ_PLANE)
// 		return (intersect_plane(r, o, rec, t_max));
// 	else
// 		return (intersect_cylinder(r, o, rec, t_max));
// }
