/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:52:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 16:36:34 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// this func caluculate pixel color.
// ヒットした点(rec)を中心にして、ピクセルの色を計算する。
// 考慮するのは、アンビエント、diffuse光、specular、反射、屈折
// 基礎でのるのは、アンビエント
// colorを育てていく
t_rgb3	calculate_lighting(t_info *info, t_hit *rec, t_ray *in_ray, int depth)
{
	t_rgb3			color;
	t_vec3			view_dir;

	view_dir = vec_scale(in_ray->direction, -1.0);
	color = apply_amb(info->amb);
	if (rec->mat == MAT_DIFFUSE)
		color = add_rgb(color, calc_direct_lighting(info, rec, view_dir));
	if (depth < MAX_DEPTH
		&& (rec->mat == MAT_MIRROR || rec->mat == MAT_METAL
			|| rec->mat == MAT_GLASS))
		color = add_rgb(color,
				calc_secondary_lighting(info, rec, in_ray, depth));
	return (color);
}
