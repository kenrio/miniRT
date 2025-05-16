/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/16 19:13:48 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray r, t_pos3 center, double radius, double *t)
{
	t_vec3		oc;
	t_quad_eq	quad;

	oc = pos_sub(r.origin, center);
	quad.a = vec_dot(r.direction, r.direction);
	quad.b = 2.0 * vec_dot(oc, r.direction);
	quad.c = vec_dot(oc, oc) - radius * radius;
	if (calc_quad_discriminant(&quad) < 0.0)
		return (false);
	solve_quad_eq(&quad);
	if ((quad.t1 < 1e-4) && (quad.t2 < 1e-4))
		return (false);
	if (quad.t1 < 1e-4 || (quad.t2 < quad.t1 && quad.t2 > 1e-4))
		*t = quad.t2;
	else
		*t = quad.t1;
	return (true);
}
