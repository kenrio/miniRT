/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/11 12:15:32 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray r, t_pos3 center, double radius)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = pos_sub(r.origin, center);
	a = v_dot(r.direction, r.direction);
	b = 2.0 * v_dot(oc, r.direction);
	c = v_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (false);
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 1e-4)
	{
		t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (t < 1e-4)
			return (false);
	}
	return (true);
}
