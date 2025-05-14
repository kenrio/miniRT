/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/15 08:31:57 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_sphere(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_vec3		oc;
	t_quad_eq	quad;
	double		t;

	oc = pos_sub(r->origin, o->data.sp.pos);
	quad.a = vec_dot(r->direction, r->direction);
	quad.b = 2.0 * vec_dot(oc, r->direction);
	quad.c = vec_dot(oc, oc) - pow(o->data.sp.diameter * 0.5, 2);

	// 判別式
	if (calc_quad_discriminant(&quad) < 0.0)
		return (false);
	
	// 解の導出
	solve_quad_eq(&quad);
	
	// 交差点2つとも描画範囲外の場合はここで無視して余分な計算を避ける
	t = quad.t1;
	if (t < T_MIN || t_max < t)
	{
		t = quad.t2;
		if (t < T_MIN || t_max < t)
			return (false);
	}
	
	// 代入
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->n = vec_normalize(pos_sub(rec->pos, o->data.sp.pos));
	rec->rgb = o->data.sp.rgb;

	return (true);
}
