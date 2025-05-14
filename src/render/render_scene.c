/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/15 08:31:19 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec);
static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max);

void	render_scene(t_info *info)
{
	int				x;
	int				y;
	double			u;
	double			v;
	t_ray			ray;
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


			// ここから描画始まる(もし衝突した場合、recに衝突情報を入れる)
			if (hit_scene(&ray, info->objs, &rec) == true)
				color = rgb_to_uint(rec.rgb);
			else
				color = BG_COLOR;


			// 当たり判定があるなら色を変える(つまり、colorを変える)
			// if (intersect_sphere(ray, info->objs->data.sp.pos, info->objs->data.sp.diameter / 2.0))
			// 	color = rgb_to_uint(info->objs->data.sp.rgb);
			// else
			// 	color = BG_COLOR;



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
	return(false);
	// else if (o->kind == E_PLANE)
	// 	return (hit_plane());
	// else
	// 	return (hit_cylinder());
}
