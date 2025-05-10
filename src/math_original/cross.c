/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:02:59 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/10 15:25:52 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 vec;

	vec.x = a.y * b.z - a.z - b.y;
	vec.y = a.z * b.x - a.x - b.z;
	vec.z = a.x * b.y - a.y - b.x;
	return (vec);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	len;
	
	len = vec_len(v);
	if (len == 0)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){v.x / len, v.y / len, v.z / len});
}
