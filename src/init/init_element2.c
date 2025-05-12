/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:00:48 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/12 19:09:20 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_sphere(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->sp.pos = parse_pos3(get_valid_token(elem, 1));
	info->sp.diameter = parse_double(get_valid_token(elem, 2));
	info->sp.rgb = parse_rgb3(get_valid_token(elem, 3));
	if (!validate_rgb(info->sp.rgb))
		info->is_init_success = false;
}

void	init_plane(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->pl.pos = parse_pos3(get_valid_token(elem, 1));
	info->pl.vec = parse_vec3(get_valid_token(elem, 2));
	info->pl.rgb = parse_rgb3(get_valid_token(elem, 3));
	if (!validate_unit_range(info->pl.vec.x)
		|| !validate_unit_range(info->pl.vec.y)
		|| !validate_unit_range(info->pl.vec.z)
		|| !validate_rgb(info->pl.rgb))
		info->is_init_success = false;
}

void	init_cylinder(t_info *info, char *elem)
{
	if (!info || !elem)
	{
		info->is_init_success = false;
		return ;
	}
	info->cy.pos = parse_pos3(get_valid_token(elem, 1));
	info->cy.vec = parse_vec3(get_valid_token(elem, 2));
	info->cy.diameter = parse_double(get_valid_token(elem, 3));
	info->cy.height = parse_double(get_valid_token(elem, 4));
	info->cy.rgb = parse_rgb3(get_valid_token(elem, 5));
	if (!validate_unit_range(info->cy.vec.x)
		|| !validate_unit_range(info->cy.vec.y)
		|| !validate_unit_range(info->cy.vec.z)
		|| !validate_rgb(info->cy.rgb))
		info->is_init_success = false;
}
