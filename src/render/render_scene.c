/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/12 20:03:32 by keishii          ###   ########.fr       */
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

	x = 0;
	y = 0;
    while (++y < WIN_H)
    {
        while (++x < WIN_W)
        {
            u = (double)x / (WIN_W - 1);
            v = 1.0 - (double)y / (WIN_H - 1);
            ray = make_ray(&info->cam, u, v);

            color = 0x000000;
            if (intersect_sphere(ray, (t_pos3){0.0 , 0.0, 20.6}, 6.3))
                color = 0x00FF0000;
			base = (unsigned char *)info->mlx.img.addr;
            dst = base + y * info->mlx.img.line_len + x * (info->mlx.img.bpp / 8);
            *(unsigned int *)dst = color;
        }
		x = 0;
    }
}

