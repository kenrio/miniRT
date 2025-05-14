/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/15 05:55:51 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_scene(t_info *info)
{
	int				x;
	int				y;
	double			u;
	double			v;
	t_ray			ray;
	unsigned int	color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			u = (double)x / (WIN_W - 1);
			v = 1.0 - (double)y / (WIN_H - 1);
			ray = make_ray(&info->cam, u, v);
			// ここから描画始まる
			if (run_hit_scene())
				color = rgb_to_uint(info->objs->data.sp.rgb);
			else
				color = BG_COLOR;



			

			// 当たり判定があるなら色を変える(つまり、colorを変える)
			// if (intersect_sphere(ray, info->objs->data.sp.pos, info->objs->data.sp.diameter / 2.0))
			// 	color = rgb_to_uint(info->objs->data.sp.rgb);
			// else
			// 	color = BG_COLOR;



			put_pixel(x, y, color, &info->mlx.img);
			x++;
		}
		y++;
	}
}
