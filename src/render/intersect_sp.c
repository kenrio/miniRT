/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/28 15:23:04 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_vec3		oc;
	t_quad_eq	quad;
	double		t;

	oc = pos_sub(r->origin, o->data.sp.pos);
	quad.a = vec_dot(r->direction, r->direction);
	quad.b = 2.0 * vec_dot(oc, r->direction);
	quad.c = vec_dot(oc, oc)
		- (0.25 * o->data.sp.diameter * o->data.sp.diameter);
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
	rec->n
		= vec_div(pos_sub(rec->pos, o->data.sp.pos), o->data.sp.diameter / 2);
	rec->rgb = o->data.sp.rgb;
	return (true);
}
