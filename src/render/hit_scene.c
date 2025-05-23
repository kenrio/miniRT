/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:48:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 16:58:23 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_obj(t_ray *r, t_obj *o, t_hit *rec, double t_max);

// hit_scene judge whether ray hit something,
// if hit , update rec.
bool	hit_scene(t_ray *r, t_obj *o, t_hit *rec)
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
			rec->mat = o->mat;
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
