/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_screen_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:04:27 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/10 15:40:11 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	calc_right_vec(t_vec3 forward)
{
	t_vec3	world_up;
	
	world_up.x = 0;
	world_up.y = 0;
	world_up.z = 1;
	return (vec_cross(world_up, forward));
}

t_vec3	calc_up_vec(t_vec3 right, t_vec3 forward)
{
	return (vec_cross(right, forward));
}
