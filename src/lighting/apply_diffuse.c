/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:07 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 16:29:29 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_diffuse(t_light *l, t_hit *rec, t_vec3 l_dir)
{
	t_rgb3	diffuse;
	double	dotnl;

	dotnl = vec_dot(rec->n, l_dir);
	diffuse = apply_light(rec->rgb, l->intensity, dotnl);
	diffuse = modulate_rgb(diffuse, l->rgb);
	return (diffuse);
}
