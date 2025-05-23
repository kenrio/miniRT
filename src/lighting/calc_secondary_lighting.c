/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_secondary_lighting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:18:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 20:44:28 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

	if (hit_scene(&reflect_ray, info->objs, &next_rec))
	{
		// hitしたobjの色を計算する
		r_color = calculate_lighting(info, &next_rec, &reflect_ray, depth + 1);
	}
	else
	{
		r_color = uint_to_rgb(BG_COLOR);
	}



	// 屈折を計算する
	return (r_color);
}
