/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:52:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 18:31:01 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_light(t_rgb3 color, double intensity, double dot_nl);

// this func caluculate pixel color.
// ヒットした点(rec)を中心にして、ピクセルの色を計算する。
// 考慮するのは、アンビエント、diffuse光、specular、反射、屈折
// 基礎でのるのは、アンビエント
// colorを育てていく

t_rgb3	calculate_lighting(t_info *info, t_hit *rec, t_ray *in_ray)
{
	t_rgb3			color;
	t_vec3			view_dir;

	// p -> cam
	view_dir = vec_scale(in_ray->direction, -1.0);

	// colorにアンビエントを適応(基礎値)
	color =	apply_amb(info->amb);

	// ここから先はまず一次光を計算しきる

	if (rec->mat == MAT_DIFFUSE)
		color = add_rgb(color, calc_direct_lighting(info, rec, view_dir));
		
	// 次に二次レイが必要な場合計算する。ここから計算量が増える(反射と屈折を考える)
	// if (rec->mat == MAT_MIRROR)
	// 	color = add_rgb(color, calc_secondary_lighting());
	
	return (color);
}
