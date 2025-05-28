/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_secondary_lighting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:18:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/28 14:29:41 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static t_vec3	calc_secondary_direction(t_ray *in_ray, t_hit *rec);
static t_ray	make_secondary_ray(t_ray *in_ray, t_hit *rec);
static t_rgb3	calc_secondary_color(t_info *info, t_hit *rec, t_ray *ray,
					int depth);

// mat == mirror, metal, glassの場合、ここに入る
// 反射を計算する
// recから反射ベクトルに向けて再度rayを発射し、色を取得した後、r_colorに値を入れる
// 屈折の場合、このベクトルをまず変える。
// 当たったら、hitしたobjの色を計算する
t_rgb3	calc_secondary_lighting(t_info *info, t_hit *rec, t_ray *in_ray,
		int depth)
{
	t_ray	secondary_ray;

	secondary_ray = make_secondary_ray(in_ray, rec);
	return (calc_secondary_color(info, rec, &secondary_ray, depth));
}

static t_ray	make_secondary_ray(t_ray *in_ray, t_hit *rec)
{
	t_vec3	dir;

	if (rec->mat == MAT_GLASS)
	{
		dir = vec_normalize(
				vec_refraction(in_ray->direction, rec->n, GLASS_IRT));
		if (vec_is_zero(dir) == true)
			dir = vec_normalize(
					vec_reflection(in_ray->direction, rec->n));
	}
	else
		dir = vec_normalize(
				vec_reflection(in_ray->direction, rec->n));
	return (
		(t_ray){pos_add_vec(rec->pos, vec_scale(dir, EPS)), dir}
	);
}

static t_rgb3	calc_secondary_color(t_info *info, t_hit *rec, t_ray *ray,
					int depth)
{
	t_hit	next_rec;
	t_rgb3	color;

	if (hit_scene(ray, info->objs, &next_rec))
	{
		color
			= calculate_lighting(info, &next_rec, ray, depth + 1);
		if (rec->mat == MAT_METAL)
		{
			color = modulate_rgb(color, rec->rgb);
			color = multi_rgb(color, METAL_GROSS);
		}
	}
	else
		color = uint_to_rgb(BG_COLOR);
	return (color);
}
