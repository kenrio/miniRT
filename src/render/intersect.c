/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/19 11:36:24 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 球と交わるか
bool	intersect_sphere(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_vec3		oc;
	t_quad_eq	quad;
	double		t;

	oc = pos_sub(r->origin, o->data.sp.pos);
	quad.a = vec_dot(r->direction, r->direction);
	quad.b = 2.0 * vec_dot(oc, r->direction);
	quad.c = vec_dot(oc, oc) - (0.25 * o->data.sp.diameter * o->data.sp.diameter);
	if (calc_quad_discriminant(&quad) < 0.0)
		return (false);
	solve_quad_eq(&quad);
	t = quad.t1;
	if (t < T_MIN || t_max < t)
	{
		t = quad.t2;
		if (t < T_MIN || t_max < t)
			return (false);
	}
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->n = vec_scale(pos_sub(rec->pos, o->data.sp.pos), 1 / o->data.sp.diameter);
	rec->rgb = o->data.sp.rgb;
	return (true);
}

// 平面と交わるか
bool	intersect_plane(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_plane	pl;
	double	t;
	double	denom;

	pl = o->data.pl;
	denom = vec_dot(r->direction, pl.vec);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vec_dot(pos_sub(pl.pos, r->origin), pl.vec) / denom;
	if (t < T_MIN ||  t_max < t)
        return (false);
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->rgb = o->data.pl.rgb;
	if (vec_dot(r->direction, pl.vec) > 0)
		rec->n = vec_scale(pl.vec, -1.0);
	else
		rec->n = pl.vec;
	return (true);
}
