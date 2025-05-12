/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:35:22 by keishii           #+#    #+#             */
/*   Updated: 2025/05/12 15:27:24 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	make_ray(t_cam *c, double u, double v)
{
	t_pos3	ray_target;

	ray_target = pos_add_vec(
		c->llc,
		v_add(
			v_scale(c->right, u * 2.0 * c->half_w),
			v_scale(c->up, v * 2.0 * c->half_h)));
	return ((t_ray){c->pos, v_norm(pos_sub(ray_target, c->pos))});
}
