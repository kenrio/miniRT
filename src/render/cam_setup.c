/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:52:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 21:56:07 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_setup(t_cam *c)
{
	t_vec3	world_up;
	double	fov_rad;

	world_up = (t_vec3){0.0, 1.0, 0.0};
	c->forward = v_norm(c->forward);
	if (fabs(c->forward.x) < 1e-8 && fabs(c->forward.z) < 1e-8)
		world_up = (t_vec3){0.0, 0.0, 1.0};
	c->right = v_norm(v_cross(c->forward, world_up));
	c->up = v_cross(c->right, c->forward);
	fov_rad = c->fov * M_PI / 180.0;
	c->half_h = tan(fov_rad / 2.0);
	c->half_w = c->half_h * c->aspect;
	c->llc = v_add(
			v_sub(
				v_sub(c->pos, v_scale(c->right, c->half_w)),
				v_scale(c->up, c->half_h)),
			c->forward);
}
