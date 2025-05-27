/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_secondary_lighting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:18:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 16:40:38 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// mat == mirror, metal, glassの場合、ここに入る
// 反射を計算する
// recから反射ベクトルに向けて再度rayを発射し、色を取得した後、r_colorに値を入れる
// 屈折の場合、このベクトルをまず変える。
// 当たったら、hitしたobjの色を計算する
t_rgb3	calc_secondary_lighting(t_info *info, t_hit *rec, t_ray *in_ray,
		int depth)
{
	t_rgb3	r_color;
	t_vec3	secondary_dir;
	t_ray	secondary_ray;
	t_hit	next_rec;

	if (rec->mat == MAT_GLASS)
	{
		secondary_dir = vec_normalize(
				vec_refraction(in_ray->direction, rec->n, GLASS_IRT));
		if (vec_is_zero(secondary_dir) == true)
			secondary_dir = vec_normalize(
					vec_reflection(in_ray->direction, rec->n));
	}
	else
		secondary_dir = vec_normalize(
				vec_reflection(in_ray->direction, rec->n));
	secondary_ray = (t_ray){pos_add_vec(rec->pos,
			vec_scale(secondary_dir, EPS)), secondary_dir};
	if (hit_scene(&secondary_ray, info->objs, &next_rec))
	{
		r_color
			= calculate_lighting(info, &next_rec, &secondary_ray, depth + 1);
		if (rec->mat == MAT_METAL)
		{
			r_color = modulate_rgb(r_color, rec->rgb);
			r_color = multi_rgb(r_color, METAL_GROSS);
		}
	}
	else
		r_color = uint_to_rgb(BG_COLOR);
	return (r_color);
}
