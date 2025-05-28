/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:04:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/28 15:23:33 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// if dot of forward_vec. & world_up_vec. is ~= 1,
// use {1,0,0}
t_vec3	calc_right_vec(t_vec3 forward)
{
	t_vec3	world_up;

	world_up = (t_vec3){0, -1, 0};
	if (fabs(vec_dot(forward, world_up)) > 0.999)
		world_up = (t_vec3){1, 0, 0};
	return (vec_cross(forward, world_up));
}

t_vec3	calc_up_vec(t_vec3 right, t_vec3 forward)
{
	return (vec_cross(right, forward));
}

t_pos3	calc_llc(t_cam *cam)
{
	t_vec3	move_left_end;
	t_vec3	move_down_end;
	t_vec3	move_llc;

	move_left_end = vec_scale(vec_scale(cam->right, cam->half_w), -1);
	move_down_end = vec_scale(vec_scale(cam->up, cam->half_h), -1);
	move_llc = vec_add(vec_add(move_left_end, move_down_end), cam->forward);
	return (pos_add_vec(cam->pos, move_llc));
}
