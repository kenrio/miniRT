/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:10:46 by anya_stella       #+#    #+#             */
/*   Updated: 2025/05/25 21:21:32 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// calclate the vertical component of a vector.
t_vec3	vec_reject(t_vec3 v, t_vec3 axis_unit)
{
	return (vec_sub(v, vec_scale(axis_unit, vec_dot(v, axis_unit))));
}

// v: incident ray,
// n: normal vactor
t_vec3	vec_reflection(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_scale(n, 2.0 * vec_dot(v, n))));
}

// v:
t_vec3	vec_refraction(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_scale(n, 2.0 * vec_dot(v, n))));
}
