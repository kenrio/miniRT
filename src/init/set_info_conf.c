/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_conf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:52:49 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/10 16:40:39 by tishihar         ###   ########.fr       */
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
	info->amb.rgb = parse_rgb3(get_valid_token(elem, 2));
	if (!validate_unit(info->amb.intensity)
		|| !validate_rgb(info->amb.rgb.r)
		|| !validate_rgb(info->amb.rgb.g)
		|| !validate_rgb(info->amb.rgb.g))
	{
		perror("amb validate failed.");
		info->is_init_success = false;
	}
}

void	set_cam(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->cam.pos = parse_pos3(get_valid_token(elem, 1));
	info->cam.forward = parse_vec3(get_valid_token(elem, 2));
	info->cam.fov = parse_double(get_valid_token(elem, 3));
	info->cam.right = vec_normalize(calc_right_vec(info->cam.forward));
	info->cam.up = calc_up_vec(info->cam.right, info->cam.forward);
	info->cam.aspect = (WIN_W / WIN_H);
	


	// TODO:他の要素も計算して入れる

	// info->cam.half_w =
	// info->cam.half_h =
	// info->cam.llc.x =
	// info->cam.llc.y =
	// info->cam.llc.z =
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
	if (get_valid_token(elem, 3) != NULL && *get_valid_token(elem, 3) != '#')
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
