/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/19 13:43:12 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec);
static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max);

void	render_scene(t_info *info)
{
	int				x;
	int				y;
	t_ray			ray;
	unsigned int	color;
	t_hit			rec;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ray = make_ray(
					&info->cam,
					((double)x / (WIN_W - 1)),
					(1.0 - (double)y / (WIN_H - 1)));
			if (hit_scene(&ray, info->objs, &rec) == true)
				color = rgb_to_uint(rec.rgb);
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
