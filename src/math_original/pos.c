/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:13:19 by keishii           #+#    #+#             */
/*   Updated: 2025/05/16 18:03:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	pos_sub(t_pos3 p1, t_pos3 p2)
{
	return (
		(t_vec3){p1.x - p2.x, p1.y - p2.y, p1.z - p2.z}
	);
}

double	distance_pos_to_pos(t_pos3 a, t_pos3 b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}
