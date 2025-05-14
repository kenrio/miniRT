/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/14 14:16:07 by anya_stella      ###   ########.fr       */
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
	unsigned char	*base;
	unsigned char	*dst;

	y = 0;
	while (++y < WIN_H)
	{
		x = 0;
		while (++x < WIN_W)
		{
			u = (double)x / (WIN_W - 1);
			v = 1.0 - (double)y / (WIN_H - 1);
			ray = make_ray(&info->cam, u, v);
			color = BG_COLOR;


			// ここから描画始まる
			if (intersect_sphere(ray, info->sp.pos, info->sp.diameter / 2.0))
				color = rgb_to_uint(info->sp.rgb);
			base = (unsigned char *)info->mlx.img.addr;
			dst
				= base + y * info->mlx.img.line_len
				+ x * (info->mlx.img.bpp / 8);
			*(unsigned int *)dst = color;
		}
	}
}
