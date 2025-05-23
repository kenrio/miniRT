/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:07 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 19:12:48 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_diffuse(t_light *l , t_hit *rec, t_vec3 l_dir)
{
	t_rgb3	diffuse;
	double	dotnl;
	
	dotnl = vec_dot(rec->n, l_dir);
	diffuse = apply_light(rec->rgb, l->intensity, dotnl);
	diffuse.r *= (double)l->rgb.r / 255.0;
    diffuse.g *= (double)l->rgb.g / 255.0;
    diffuse.b *= (double)l->rgb.b / 255.0;
	return (diffuse);
}
