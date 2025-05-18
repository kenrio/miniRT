/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/17 17:18:08 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec);
static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max);

t_rgb3	apply_light(t_rgb3 obj_color, double light_ratio, double dot_nl)
{
	t_rgb3	output_color;
	double	brightness;

	brightness = light_ratio * fmax(0, dot_nl);
	output_color.r = (unsigned char)fmin(obj_color.r * brightness, 255);
	output_color.g = (unsigned char)fmin(obj_color.g * brightness, 255);
	output_color.b = (unsigned char)fmin(obj_color.b * brightness, 255);
	return (output_color);
}

bool	is_in_shadow(t_info *info, t_pos3 point, t_pos3 light_pos)
{
	t_ray	shadow_ray;
	t_hit	rec;
	t_vec3	shadow_dir;
	double	light_dist;

	shadow_dir = vec_normalize(pos_sub(light_pos, point));
	shadow_ray.origin = pos_add_vec(point, vec_scale(shadow_dir, 0.001));
	shadow_ray.direction = shadow_dir;
	if (hit_scene(&shadow_ray, info->objs, &rec))
	{
		light_dist = vec_len(pos_sub(light_pos, point));
		if (rec.t < light_dist)
			return (true);
	}
	return (false);
}

void	render_scene(t_info *info)
{
	int				x;
	int				y;
	double			u;
	double			v;
	double			brightness;
	t_ray			ray;
	t_vec3			light_direction;
	t_rgb3			ambient;
	t_rgb3			diffuse;
	unsigned int	color;
	t_hit			rec;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			u = (double)x / (WIN_W - 1);
			v = 1.0 - (double)y / (WIN_H - 1);
			ray = make_ray(&info->cam, u, v);
			if (hit_scene(&ray, info->objs, &rec) == true)
			{
				if (info->lights->value.pos.z < rec.pos.z)
				    light_direction = vec_normalize(pos_sub(info->lights->value.pos, rec.pos));
				else
				    light_direction = vec_normalize(pos_sub(rec.pos, info->lights->value.pos));
				if (is_in_shadow(info, rec.pos, info->lights->value.pos))
				{
			        brightness = fmax(0, vec_dot(rec.n, light_direction)) * 0.5;
			        ambient = apply_light(info->amb.rgb, info->amb.intensity, 1.0);
			        diffuse = apply_light(rec.rgb, info->lights->value.intensity, brightness);
			        rec.rgb.r = fmin(ambient.r + diffuse.r, 255);
			        rec.rgb.g = fmin(ambient.g + diffuse.g, 255);
			        rec.rgb.b = fmin(ambient.b + diffuse.b, 255);
				}
				else
				{
					brightness = fmax(0, vec_dot(rec.n, light_direction));
					ambient = apply_light(info->amb.rgb, info->amb.intensity, 1.0);
					diffuse = apply_light(rec.rgb, info->lights->value.intensity, brightness);
					rec.rgb.r = fmin(ambient.r + diffuse.r, 255);
					rec.rgb.g = fmin(ambient.g + diffuse.g, 255);
					rec.rgb.b = fmin(ambient.b + diffuse.b, 255);
				}
				color = rgb_to_uint(rec.rgb);
			}
			else
				color = BG_COLOR;
			put_pixel(x, y, color, &info->mlx.img);
			x++;
		}
		y++;
	}
}

// rayとobjが衝突するかどうかを判定し、recにぶち込む関数
static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec)
{
	bool	hit_any;
	t_hit	temp;
	double	most_close_d;
	
	hit_any = false;
	most_close_d = T_MAX;
	while (o)
	{
		if (hit_obj(r, o, &temp, most_close_d) == true)
		{
			hit_any = true;
			most_close_d = temp.t;
			*rec = temp;
		}
		o = o->next;
	}
	return (hit_any);
}

static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	if (o->kind == OBJ_SPHERE)
		return (intersect_sphere(r, o, rec, t_max));
	else if (o->kind == OBJ_PLANE)
		return (intersect_plane(r, o, rec, t_max));
	else
		return (intersect_cylinder(r, o, rec, t_max));
}
