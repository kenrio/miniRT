/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/06 14:43:10 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_scene(t_mlx *m, t_cam *cam)
{
    for (int y = 0; y < WIN_H; ++y)
    {
        for (int x = 0; x < WIN_W; ++x)
        {
            double u = (double)x / (WIN_W-1);
            double v = 1.0 - (double)y / (WIN_H-1);
            t_ray ray = make_ray(cam, u, v);

            unsigned int color = 0x000000;      // 背景
            double t;
            if (hit_sphere(ray, (t_vec3){0.0 , 0.0, 20.6}, 6.3, &t))
                color = 0x00FF0000;             // 赤い球

            char *dst = m->img.addr + y * m->img.line_len + x * (m->img.bpp/8);
            *(unsigned int *)dst = color;
        }
    }
}

