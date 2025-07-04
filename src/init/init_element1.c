/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:52:49 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/22 05:56:08 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// element is formated, "A 0.2 255,255,255"
void	init_amb(t_info *info, char *elem)
{
	if (!info || !elem || info->amb.is_register)
	{
		if (info->amb.is_register)
			perror("amb define again.");
		info->is_init_success = false;
		return ;
	}
	info->amb.intensity = parse_double(get_valid_token(elem, 1));
	info->amb.rgb = parse_rgb3(get_valid_token(elem, 2));
	if (!validate_unit(info->amb.intensity) || !validate_rgb(info->amb.rgb))
	{
		perror("amb validate failed.");
		info->is_init_success = false;
	}
	info->amb.is_register = true;
}

void	init_cam(t_info *info, char *elem)
{
	if (!info || !elem || info->cam.is_register)
	{
		if (info->cam.is_register)
			perror("cam define again.");
		info->is_init_success = false;
		return ;
	}
	info->cam.pos = parse_pos3(get_valid_token(elem, 1));
	info->cam.fov = parse_double(get_valid_token(elem, 3));
	info->cam.forward = vec_normalize(parse_vec3(get_valid_token(elem, 2)));
	info->cam.right = vec_normalize(calc_right_vec(info->cam.forward));
	info->cam.up = calc_up_vec(info->cam.right, info->cam.forward);
	info->cam.fov_rad = (info->cam.fov * PIE) / 180;
	info->cam.aspect = (WIN_W / WIN_H);
	info->cam.half_h = tan(info->cam.fov_rad / 2.0);
	info->cam.half_w = info->cam.half_h * info->cam.aspect;
	info->cam.llc = calc_llc(&info->cam);
	if (!validate_unit_range(info->cam.forward.x)
		|| !validate_unit_range(info->cam.forward.y)
		|| !validate_unit_range(info->cam.forward.z)
		|| !validate_rad(info->cam.fov))
		info->is_init_success = false;
	info->cam.is_register = true;
}

void	init_lights(t_info *info, char *elem)
{
	t_light_node	*node;
	t_rgb3			rgb;

	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	if (get_valid_token(elem, 3) != NULL && *get_valid_token(elem, 3) != '#')
		rgb = parse_rgb3(get_valid_token(elem, 3));
	else
		rgb = (t_rgb3){255, 255, 255};
	node = new_light_node(
			parse_pos3(get_valid_token(elem, 1)),
			parse_double(get_valid_token(elem, 2)),
			rgb);
	if (!node
		|| !validate_unit(node->value.intensity)
		|| !validate_rgb(node->value.rgb))
	{
		info->is_init_success = false;
		return ;
	}
	node->next = info->lights;
	info->lights = node;
}
