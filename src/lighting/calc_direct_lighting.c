/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_direct_lighting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:12:14 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 18:29:48 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_shadow(t_info *info, t_pos3 point, t_vec3 ray_dir, t_pos3 light_pos);

// calculate direct lighting.
// for example, diffuse light, specular.
t_rgb3	calc_direct_lighting(t_info *info, t_hit *rec, t_vec3 view_dir)
{
	t_light_node	*curr;
	t_light			light;
	t_vec3			light_dir;
	t_rgb3			color;

	color = (t_rgb3){0,0,0};
	curr = info->lights;
	while (curr)
	{
		// 1つのライトについての寄与を見ていく
		// スペキュラーと、diffuseをみる
		light = curr->value;
		light_dir = vec_normalize(pos_sub(light.pos, rec->pos));

		if (is_in_shadow(info, rec->pos, light_dir, light.pos))
		{
			curr = curr->next;
			continue;
		}
		
		// ここでdiffuseを計算する
		color = add_rgb(color, apply_diffuse(&light, rec, light_dir));

		// ここでspecularを計算する
		color = add_rgb(color, apply_specular(view_dir, light_dir, rec->n, light.intensity));

		
		curr = curr->next;
	}
	return (color);
	
}

static bool	is_in_shadow(t_info *info, t_pos3 point, t_vec3 ray_dir, t_pos3 light_pos)
{
	t_ray	shadow_ray;
	t_hit	rec;
	double	light_dist;

	shadow_ray.origin = pos_add_vec(point, vec_scale(ray_dir, 0.001));
	shadow_ray.direction = ray_dir;
	if (hit_scene(&shadow_ray, info->objs, &rec))
	{
		light_dist = vec_len(pos_sub(light_pos, point));
		if (rec.t < light_dist)
			return (true);
	}
	return (false);
}
