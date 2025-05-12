/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_screen_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:04:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/10 16:52:37 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// if dot of forward_vec. & world_up_vec. is ~= 1,
// use {1,0,0}
t_vec3	calc_right_vec(t_vec3 forward)
{
	t_vec3	world_up;

	world_up = (t_vec3){0, 0, 1};
	if (fabs(vec_dot(forward, world_up)) > 0.999)
		world_up = (t_vec3){1, 0, 0};
	return (vec_cross(world_up, forward));
}

t_vec3	calc_up_vec(t_vec3 right, t_vec3 forward)
{
	return (vec_cross(right, forward));
}
