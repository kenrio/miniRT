/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_specular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:31:57 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/22 10:07:12 by tishihar         ###   ########.fr       */
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

	// reflectとviewの内積
	specular = pow(fmax(vec_dot(reflect, v), 0.0), 32.0);// めっちゃちっちゃい値0.1とか
	return (apply_light((t_rgb3){255, 255, 255}, l_intensity * 0.5, specular));
}
