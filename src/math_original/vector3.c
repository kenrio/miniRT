/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:10:46 by anya_stella       #+#    #+#             */
/*   Updated: 2025/05/26 08:39:25 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// calclate the vertical component of a vector.
t_vec3	vec_reject(t_vec3 v, t_vec3 axis_unit)
{
	return (vec_sub(v, vec_scale(axis_unit, vec_dot(v, axis_unit))));
}

// v: incident direction,
// n: normal vactor
t_vec3	vec_reflection(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_scale(n, 2.0 * vec_dot(v, n))));
}

// v: incident direction,
// n: normal vactor
// irt: inner eta
t_vec3	vec_refraction(t_vec3 v, t_vec3 n, double ior)
{
	double	cosi;
	double	cost;
	double	etai;
	double	etat;
	t_vec3	nn;
	double eta;

	etai = 1.0;
	etat = ior;
	nn = n;
	cosi = -1.0 * vec_dot(v, n);
	if (cosi < 0.0)
	{
		cosi = -cosi;
		nn = vec_scale(n, -1.0);
		etai = ior;
		etat = 1.0;
	}
	eta = etai / etat;
	cost = 1 - eta * eta * (1 - cosi * cosi);

	// 全反射
	if (cost < 0.0)
		return ((t_vec3){0, 0, 0});
	return (vec_add(vec_scale(v, eta), vec_scale(nn, (eta * cosi - sqrt(cost)))));
}

bool	vec_is_zero(t_vec3	vec)
{
	return (vec.x == 0 && vec.y == 0 && vec.z == 0);
}
