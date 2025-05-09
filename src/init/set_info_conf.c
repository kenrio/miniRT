/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_conf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:52:49 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/09 18:52:46 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// element is formated, "A 0.2 255,255,255"
void	set_amb(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->amb.intensity = parse_double(get_valid_token(elem, 1));
	info->amb.rgb.r = parse_3int(get_valid_token(elem, 2), 0);
	info->amb.rgb.g = parse_3int(get_valid_token(elem, 2), 1);
	info->amb.rgb.b = parse_3int(get_valid_token(elem, 2), 2);
	if (!validate_unit(info->amb.intensity)
		|| !validate_rgb(info->amb.rgb.r)
		|| !validate_rgb(info->amb.rgb.g)
		|| !validate_rgb(info->amb.rgb.g))
		info->is_init_success = false;
}

void	set_cam(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->cam.pos.x = parse_3double(get_valid_token(elem, 1), 0);
	info->cam.pos.y = parse_3double(get_valid_token(elem, 1), 1);
	info->cam.pos.z = parse_3double(get_valid_token(elem, 1), 2);
	info->cam.forward.x = parse_3double(get_valid_token(elem, 2), 0);
	info->cam.forward.y = parse_3double(get_valid_token(elem, 2), 1);
	info->cam.forward.z = parse_3double(get_valid_token(elem, 2), 2);
	info->cam.fov = parse_double(get_valid_token(elem, 3));
	// TODO:他の要素も計算して入れる

	if (!validate_unit_range(info->cam.forward.x)
		|| !validate_unit_range(info->cam.forward.y)
		|| !validate_unit_range(info->cam.forward.z)
		|| !validate_rad(info->cam.fov))
		info->is_init_success = false;
}

// L -40.0,50.0,20.0 0.6 255,255,255
void	set_light(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->light.pos.x = parse_3double(get_valid_token(elem, 1), 0);
	info->light.pos.y = parse_3double(get_valid_token(elem, 1), 1);
	info->light.pos.z = parse_3double(get_valid_token(elem, 1), 2);
	info->light.intensity = parse_double(get_valid_token(elem,2));
	if (get_valid_token(elem, 3) != NULL)
	{
		info->light.rgb.r = parse_3int(get_valid_token(elem, 3), 0);
		info->light.rgb.g = parse_3int(get_valid_token(elem, 3), 1);
		info->light.rgb.b = parse_3int(get_valid_token(elem, 3), 2);
	}
	else
	{
		info->light.rgb.r = 255;
		info->light.rgb.g = 255;
		info->light.rgb.b = 255;
	}
	if (!validate_unit(info->light.intensity)
		|| !validate_rgb(info->light.rgb.r)
		|| !validate_rgb(info->light.rgb.g)
		|| !validate_rgb(info->light.rgb.b))
		info->is_init_success = false;
}
