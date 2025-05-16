/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:00:48 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/14 16:59:20 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*parse_sphere(char *elem, t_sphere *sp);
static t_plane *parse_plane(char *elem, t_plane *pl);
static t_cylinder *parse_cylinder(char *elem, t_cylinder *cy);

void	init_objs(t_info *info, char *elem, t_elem type)
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
	
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	if (type == E_SPHERE)
	{
		if (!parse_sphere(elem, &sp))
		{
			info->is_init_success = false;
			return ;
		}
		info->objs = add_obj_front(info->objs, new_obj_sp(sp));
	}
	else if (type == E_PLANE)
	{
		if (!parse_plane(elem, &pl))
		{
			info->is_init_success = false;
			return ;
		}
		info->objs = add_obj_front(info->objs, new_obj_pl(pl));
	}
	else if (type == E_CYLINDER)
	{
		if (!parse_cylinder(elem, &cy))
		{
			info->is_init_success = false;
			return ;
		}
		info->objs = add_obj_front(info->objs, new_obj_cy(cy));
	}
	else
		return ;
}

static t_sphere	*parse_sphere(char *elem, t_sphere *sp)
{
	sp->pos = parse_pos3(get_valid_token(elem, 1));
	sp->diameter = parse_double(get_valid_token(elem, 2));
	sp->rgb = parse_rgb3(get_valid_token(elem, 3));
	if (!validate_rgb(sp->rgb))
		return (NULL);
	return (sp);
}

static t_plane *parse_plane(char *elem, t_plane *pl)
{
	pl->pos = parse_pos3(get_valid_token(elem, 1));
	pl->vec = parse_vec3(get_valid_token(elem, 2));
	pl->rgb = parse_rgb3(get_valid_token(elem, 3));
	if (!validate_rgb(pl->rgb)
		|| !validate_unit_range(pl->vec.x)
		|| !validate_unit_range(pl->vec.y)
		|| !validate_unit_range(pl->vec.z))
		return (NULL);
	return (pl);
}

static t_cylinder *parse_cylinder(char *elem, t_cylinder *cy)
{
	cy->pos = parse_pos3(get_valid_token(elem, 1));
	cy->vec = parse_vec3(get_valid_token(elem, 2));
	cy->diameter = parse_double(get_valid_token(elem, 3));
	cy->height = parse_double(get_valid_token(elem, 4));
	cy->rgb = parse_rgb3(get_valid_token(elem, 5));
	if (!validate_unit_range(cy->vec.x)
		|| !validate_unit_range(cy->vec.y)
		|| !validate_unit_range(cy->vec.z)
		|| !validate_rgb(cy->rgb))
		return (NULL);
	return (cy);
}
