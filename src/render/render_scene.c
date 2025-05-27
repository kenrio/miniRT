/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:49:55 by keishii           #+#    #+#             */
/*   Updated: 2025/05/27 16:49:56 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// this fuctiuon emit a ray of light,
// if ray hit something, update "t_hit rec".
// void	render_scene(t_info *info)
// {
// 	int				x;
// 	int				y;
// 	t_ray			ray;
// 	unsigned int	color;
// 	t_hit			rec;

// 	y = 0;
// 	while (y < WIN_H)
// 	{
// 		x = 0;
// 		while (x < WIN_W)
// 		{
// 			ray = make_ray(
// 					&info->cam,
// 					((double)x / (WIN_W - 1)),
// 					(1.0 - (double)y / (WIN_H - 1)));
// 			if (hit_scene(&ray, info->objs, &rec) == true)
// 			{
// 				color
// 					= rgb_to_uint(
// 						calculate_lighting(info, &rec, &ray, 0));
// 			}
// 			else
// 				color = BG_COLOR;
// 			put_pixel(x, y, color, &info->mlx.img);
// 			x++;
// 		}
// 		y++;
// 	}
// }
