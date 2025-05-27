/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:31:57 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 16:28:36 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// view_vec: p->cam,
// light_vec: p to light,
// n: normal vec
t_rgb3	apply_specular(t_vec3 v, t_vec3 l, t_vec3 n, double l_intensity)
{
	t_vec3	reflect;
	double	specular;

	reflect = vec_normalize(vec_reflection(vec_scale(l, -1.0), n));
	specular = pow(fmax(vec_dot(reflect, v), 0.0), SP_SHININESS);
	return (
		apply_light((t_rgb3){255, 255, 255}, l_intensity * SP_KS, specular)
	);
}
