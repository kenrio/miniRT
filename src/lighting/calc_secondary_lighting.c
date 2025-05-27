/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_secondary_lighting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:18:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/25 09:59:28 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// mat == mirror, metalの場合、ここに入る
t_rgb3	calc_secondary_lighting(t_info *info, t_hit *rec, t_ray *in_ray, int depth)
{
	t_rgb3	r_color;
	t_vec3	reflect_vec;
	t_ray	reflect_ray;
	t_hit	next_rec;

	// 反射を計算する
	// recから反射ベクトルに向けて再度rayを発射し、色を取得した後、r_colorに値を入れる
	reflect_vec = vec_normalize(vec_reflection(in_ray->direction, rec->n));
	reflect_ray = (t_ray){pos_add_vec(rec->pos, vec_scale(reflect_vec, EPS)), reflect_vec};

	// 当たったら、hitしたobjの色を計算する
	if (hit_scene(&reflect_ray, info->objs, &next_rec))
	{
		r_color = calculate_lighting(info, &next_rec, &reflect_ray, depth + 1);

		// このままだと鏡面だけなので、metalの場合物質の色を加算
		if (rec->mat == MAT_METAL)
		{
			r_color = modulate_rgb(r_color, rec->rgb);
			r_color.r *= 0.9;
			r_color.g *= 0.9;
			r_color.b *= 0.9;
		}
	}
	else
	{
		r_color = uint_to_rgb(BG_COLOR);
	}



	// 屈折を計算する
	return (r_color);
}
