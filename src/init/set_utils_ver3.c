/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils_ver3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:13:02 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/09 20:17:27 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pos3	parse_pos3(char *token)
{
	t_pos3	pos;

	pos.x = parse_3double(token, 0);
	pos.y = parse_3double(token, 1);
	pos.z = parse_3double(token, 2);
	return (pos);
}

t_vec3	parse_vec3(char *token)
{
	t_vec3	vec;

	vec.x = parse_3double(token, 0);
	vec.y = parse_3double(token, 1);
	vec.z = parse_3double(token, 2);
	return (vec);
}

t_rgb3	parse_rgb3(char *token)
{
	t_rgb3	rgb;

	rgb.r = parse_3double(token, 0);
	rgb.g = parse_3double(token, 1);
	rgb.b = parse_3double(token, 2);
	return (rgb);
}
