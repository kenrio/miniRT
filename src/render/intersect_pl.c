/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/28 15:22:59 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_plane(t_ray *r, t_obj *o, t_hit *rec, double t_max)
{
	t_plane	pl;
	double	t;
	double	denom;

	pl = o->data.pl;
	denom = vec_dot(r->direction, pl.vec);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vec_dot(pos_sub(pl.pos, r->origin), pl.vec) / denom;
	if (t < T_MIN || t_max < t)
		return (false);
	rec->t = t;
	rec->pos = ray_at(r, t);
	rec->rgb = o->data.pl.rgb;
	if (vec_dot(r->direction, pl.vec) > 0)
		rec->n = vec_scale(pl.vec, -1.0);
	else
		rec->n = pl.vec;
	return (true);
}
