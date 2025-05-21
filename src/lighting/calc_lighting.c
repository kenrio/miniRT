/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:52:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/22 07:32:25 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_light(t_rgb3 color, double intensity, double dot_nl);
bool	is_in_shadow(t_info *info, t_pos3 point, t_vec3 ray_dir, t_pos3 light_pos);

// this func caluculate pixel color.
// ヒットした点(rec)を中心にして、ピクセルの色を計算する。
// 考慮するのは、アンビエント、diffuse光、specular、反射、屈折
t_rgb3	calculate_lighting(t_info *info, t_hit *rec)
{
	t_rgb3			color_rgb;
	t_rgb3			ambient;
	t_rgb3			diffuse;
	t_rgb3			diffuse_total;
	double			brightness;
	t_vec3			light_direction;
	t_light_node	*light_node;
	t_light			light;


	light_node = info->lights;

	// アンビエント光
	ambient = apply_light(info->amb.rgb, info->amb.intensity, 1.0);
	
	// diffuse光
	diffuse_total = (t_rgb3){0, 0, 0};// (diffuse =)

	// スペキュラー光
	
	while (light_node)
	{
		// lightの基礎情報
		light = light_node->value;
		light_direction = vec_normalize(pos_sub(light.pos, rec->pos));

		// 影の中じゃない場合、diffuse拡散光を計算し、diffuse_totalを成長させる
		if (!is_in_shadow(info, rec->pos, light_direction, light.pos))
		{
			// diffuseを計算し作成する
			brightness = vec_dot(rec->n, light_direction);
			diffuse = apply_light(rec->rgb, light.intensity, brightness);
			diffuse.r *= (double)light.rgb.r / 255.0;
			diffuse.g *= (double)light.rgb.g / 255.0;
			diffuse.b *= (double)light.rgb.b / 255.0;

			// diffuseに足し上げていく。
			diffuse_total.r += diffuse.r;
			diffuse_total.g += diffuse.g;
			diffuse_total.b += diffuse.b;


			// ↓
			// 改
			// diffuse_total += calc_per_diffuse();
		}
		light_node = light_node->next;

	}
	color_rgb.r = fmin(ambient.r + diffuse_total.r, 255);
	color_rgb.g = fmin(ambient.g + diffuse_total.g, 255);
	color_rgb.b = fmin(ambient.b + diffuse_total.b, 255);
	return (color_rgb);
}

t_rgb3	apply_light(t_rgb3 color, double intensity, double dot_nl)
{
	t_rgb3	output_color;
	double	brightness;

	brightness = intensity * fmax(0, dot_nl);
	output_color.r = fmin(color.r * brightness, 255);
	output_color.g = fmin(color.g * brightness, 255);
	output_color.b = fmin(color.b * brightness, 255);
	return (output_color);
}

bool	is_in_shadow(t_info *info, t_pos3 point, t_vec3 ray_dir, t_pos3 light_pos)
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
