/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_secondary_lighting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:18:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/28 14:39:40 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray	make_secondary_ray(t_ray *in_ray, t_hit *rec);

t_rgb3	calc_secondary_lighting(t_info *info, t_hit *rec, t_ray *in_ray,
		int depth)
{
	t_ray	secondary_ray;
	t_hit	next_rec;
	t_rgb3	color;

	secondary_ray = make_secondary_ray(in_ray, rec);
	if (hit_scene(&secondary_ray, info->objs, &next_rec))
	{
		color
			= calculate_lighting(info, &next_rec, &secondary_ray, depth + 1);
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
