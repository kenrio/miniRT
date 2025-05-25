/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <wingstonetone9.8@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:07 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/25 09:50:27 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_diffuse(t_light *l , t_hit *rec, t_vec3 l_dir)
{
	t_rgb3	diffuse;
	double	dotnl;
	
	dotnl = vec_dot(rec->n, l_dir);
	diffuse = apply_light(rec->rgb, l->intensity, dotnl);
	diffuse = modulate_rgb(diffuse, l->rgb);
	return (diffuse);
}
