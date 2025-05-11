/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/11 09:40:24 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray r, t_vec3 center, double radius)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = v_sub(r.orig, center);
	a = v_dot(r.dir, r.dir);
	b = 2 * v_dot(oc, r.dir);
	c = v_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t = (-b - sqrt(discriminant)) / (2 * a);
	if (t < 1e-4)
	{
		t = (-b + sqrt(discriminant)) / (2 * a);
		if (t < 1e-4)
			return (false);
	}
	return (true);
}
