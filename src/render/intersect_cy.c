/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:33:17 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/28 15:22:50 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_cyl_side(t_ray *r, t_obj *o, t_hit *rec, double t_max);
static bool	hit_cyl_cap_top(t_ray *r, t_obj *o, t_hit *rec, double t_max);
static bool	hit_cyl_cap_bottom(t_ray *r, t_obj *o, t_hit *rec, double t_max);
static bool	solve_eq(t_ray *r, t_obj *o, t_quad_eq *quad);

bool	intersect_cylinder(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	bool				hit_any;
	double				t_closest;
	t_hit				tmp;

	hit_any = false;
	t_closest = t_max;
	if (hit_cyl_side(r, o, &tmp, t_closest))
	{
		hit_any = true;
		t_closest = tmp.t;
		*rec = tmp;
	}
	if (hit_cyl_cap_top(r, o, &tmp, t_closest) && tmp.t < t_closest)
	{
		hit_any = true;
		t_closest = tmp.t;
		*rec = tmp;
	}
	if (hit_cyl_cap_bottom(r, o, &tmp, t_closest) && tmp.t < t_closest)
	{
		hit_any = true;
		t_closest = tmp.t;
		*rec = tmp;
	}
	return (hit_any);
}

static bool	hit_cyl_side(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_quad_eq	quad;
	double		t;
	double		axis_h;
	t_cylinder	cy;

	cy = o->data.cy;
	if (solve_eq(r, o, &quad) == false)
		return (false);
	t = quad.t1;
	if (t < T_MIN || t_max < t)
	{
		t = quad.t2;
		if (t < T_MIN || t_max < t)
			return (false);
	}
	axis_h = vec_dot(cy.axis,
			vec_add(pos_sub(r->origin, cy.pos), vec_scale(r->direction, t)));
	if (fabs(axis_h) > (cy.height / 2))
		return (false);
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->n = vec_div(pos_sub(rec->pos, pos_add_vec(cy.pos,
					vec_scale(cy.axis, axis_h))), cy.diameter / 2);
	rec->rgb = cy.rgb;
	return (true);
}

static bool	hit_cyl_cap_top(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_pos3		cap_c;
	t_pos3		p;
	double		t;
	double		denom;
	t_cylinder	cy;

	cy = o->data.cy;
	cap_c = pos_add_vec(cy.pos, vec_scale(cy.axis, (cy.height / 2)));
	denom = vec_dot(cy.axis, r->direction);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vec_dot(cy.axis, pos_sub(cap_c, r->origin)) / denom;
	if (t < T_MIN || t_max < t)
		return (false);
	p = ray_at(r, t);
	if (vec_len2(pos_sub(p, cap_c)) > (0.25 * cy.diameter * cy.diameter))
		return (false);
	rec->t = t;
	rec->pos = p;
	rec->rgb = cy.rgb;
	if (denom < 0)
		rec->n = cy.axis;
	else
		rec->n = vec_scale(o->data.cy.axis, -1);
	return (true);
}

static bool	hit_cyl_cap_bottom(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_pos3		cap_c;
	t_pos3		p;
	double		t;
	double		denom;
	t_cylinder	cy;

	cy = o->data.cy;
	cap_c = pos_add_vec(cy.pos, vec_scale(cy.axis, -(cy.height / 2)));
	denom = vec_dot(cy.axis, r->direction);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vec_dot(cy.axis, pos_sub(cap_c, r->origin)) / denom;
	if (t < T_MIN || t_max < t)
		return (false);
	p = ray_at(r, t);
	if (vec_len2(pos_sub(p, cap_c)) > (0.25 * cy.diameter * cy.diameter))
		return (false);
	rec->t = t;
	rec->pos = p;
	rec->rgb = cy.rgb;
	if (denom < 0)
		rec->n = cy.axis;
	else
		rec->n = vec_scale(o->data.cy.axis, -1);
	return (true);
}

static bool	solve_eq(t_ray *r, t_obj *o, t_quad_eq *quad)
{
	t_vec3		vec_d_reject;
	t_vec3		vec_op_reject;
	t_cylinder	cy;

	cy = o->data.cy;
	vec_d_reject = vec_reject(r->direction, cy.axis);
	vec_op_reject = vec_reject(pos_sub(cy.pos, r->origin), cy.axis);
	quad->a = vec_dot(vec_d_reject, vec_d_reject);
	quad->b = -2.0 * vec_dot(vec_d_reject, vec_op_reject);
	quad->c = vec_dot(vec_op_reject, vec_op_reject)
		- (0.25 * cy.diameter * cy.diameter);
	if (calc_quad_discriminant(quad) < 0.0)
		return (false);
	solve_quad_eq(quad);
	return (true);
}
