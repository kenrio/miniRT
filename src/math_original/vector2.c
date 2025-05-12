/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:07:30 by keishii           #+#    #+#             */
/*   Updated: 2025/05/12 18:12:54 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return (
		(t_vec3){a.x + b.x, a.y + b.y, a.z + b.z}
	);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return (
		(t_vec3){a.x - b.x, a.y - b.y, a.z - b.z}
	);
}

t_vec3	vec_scale(t_vec3 v, double k)
{
	return (
		(t_vec3){v.x * k, v.y * k, v.z * k}
	);
}
