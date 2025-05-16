/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/16 17:00:38 by tishihar         ###   ########.fr       */
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
	quad.c = vec_dot(oc, oc) - pow(o->data.sp.diameter * 0.5, 2);
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
	rec->n = vec_normalize(pos_sub(rec->pos, o->data.sp.pos));
	rec->rgb = o->data.sp.rgb;
	return (true);
}

// 平面と交わるか
bool	intersect_plane(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_plane	pl;
	double	t;

	pl = o->data.pl;
	t = vec_dot(pos_sub(pl.pos, r->origin), pl.vec) / vec_dot(r->direction, pl.vec);
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

// 円柱と交わるか
bool	intersect_cylinder(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_vec3		vec_d_reject;
	t_vec3		vec_op_reject;
	t_vec3		axis;
	t_quad_eq	quad;
	double		t;
	double		lim;
	
	axis = vec_normalize(o->data.cy.vec);
	vec_d_reject = vec_reject(r->direction, axis);
	vec_op_reject = vec_reject(pos_sub(o->data.cy.pos, r->origin), axis);
	quad.a = vec_dot(vec_d_reject, vec_d_reject);
	quad.b = -2.0 * vec_dot(vec_d_reject, vec_op_reject);
	quad.c = vec_dot(vec_op_reject, vec_op_reject) - pow(o->data.cy.diameter * 0.5, 2);
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
	lim = vec_dot(axis, vec_add(pos_sub(r->origin, o->data.cy.pos), vec_scale(r->direction, t)));
	if (fabs(lim) > (o->data.cy.height / 2))
		return (false);
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->n = vec_normalize(pos_sub(rec->pos, pos_add_vec(o->data.cy.pos, vec_scale(axis, lim))));
	rec->rgb = o->data.cy.rgb;
	return (true);
}

