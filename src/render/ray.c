/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:35:22 by keishii           #+#    #+#             */
/*   Updated: 2025/05/19 13:36:05 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	make_ray(t_cam *c, double u, double v)
{
	t_pos3	ray_target;

	ray_target = pos_add_vec(
			c->llc,
			vec_add(
				vec_scale(c->right, u * 2.0 * c->half_w),
				vec_scale(c->up, v * 2.0 * c->half_h)));
	return ((t_ray){c->pos, vec_normalize(pos_sub(ray_target, c->pos))});
}

t_pos3	ray_at(t_ray *ray, double distance)
{
	return (pos_add_vec(ray->origin, vec_scale(ray->direction, distance)));
}
