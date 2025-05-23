/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:00:48 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 13:43:08 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere		*parse_sphere(char *elem, t_sphere *sp);
static t_plane		*parse_plane(char *elem, t_plane *pl);
static t_cylinder	*parse_cylinder(char *elem, t_cylinder *cy);

void	init_objs(t_info *info, char *elem, t_elem type)
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
	t_mat		mat;
	if (!info || !elem)
		return ((void)(info && (info->is_init_success = false)));
	mat = parse_material(get_valid_token(elem, 1));
	if (mat == MAT_NONE)
		return ((void)(info && (info->is_init_success = false)));
	if (type == E_SPHERE)
	{
		if (!parse_sphere(elem, &sp))
			return ((void)(info && (info->is_init_success = false)));
		info->objs = add_obj_front(info->objs, new_obj_sp(sp, mat));
	}
	else if (type == E_PLANE)
	{
		if (!parse_plane(elem, &pl))
			return ((void)(info && (info->is_init_success = false)));
		info->objs = add_obj_front(info->objs, new_obj_pl(pl, mat));
	}
	else if (type == E_CYLINDER)
	{
		if (!parse_cylinder(elem, &cy))
			return ((void)(info && (info->is_init_success = false)));
		info->objs = add_obj_front(info->objs, new_obj_cy(cy, mat));
	}
}

static t_sphere	*parse_sphere(char *elem, t_sphere *sp)
{
	sp->pos = parse_pos3(get_valid_token(elem, 2));
	sp->diameter = parse_double(get_valid_token(elem, 3));
	sp->rgb = parse_rgb3(get_valid_token(elem, 4));
	if (!validate_rgb(sp->rgb))
		return (NULL);
	return (sp);
}

static t_plane	*parse_plane(char *elem, t_plane *pl)
{
	pl->pos = parse_pos3(get_valid_token(elem, 2));
	pl->vec = vec_normalize(parse_vec3(get_valid_token(elem, 3)));
	pl->rgb = parse_rgb3(get_valid_token(elem, 4));
	if (!validate_rgb(pl->rgb)
		|| !validate_unit_range(pl->vec.x)
		|| !validate_unit_range(pl->vec.y)
		|| !validate_unit_range(pl->vec.z))
		return (NULL);
	return (pl);
}

static t_cylinder	*parse_cylinder(char *elem, t_cylinder *cy)
{
	cy->pos = parse_pos3(get_valid_token(elem, 2));
	cy->axis = vec_normalize(parse_vec3(get_valid_token(elem, 3)));
	cy->diameter = parse_double(get_valid_token(elem, 4));
	cy->height = parse_double(get_valid_token(elem, 5));
	cy->rgb = parse_rgb3(get_valid_token(elem, 6));
	if (!validate_unit_range(cy->axis.x)
		|| !validate_unit_range(cy->axis.y)
		|| !validate_unit_range(cy->axis.z)
		|| !validate_rgb(cy->rgb))
		return (NULL);
	return (cy);
}
