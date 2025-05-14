/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:59:43 by keishii           #+#    #+#             */
/*   Updated: 2025/05/14 17:51:25 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_light(t_rgb3 obj_color, double light_ratio, double dot_nl)
{
	t_rgb3	output_color;
	double	brightness;

	brightness = light_ratio * fmax(0, dot_nl);
	output_color.r = (unsigned char)fmin(obj_color.r * brightness, 255);
	output_color.g = (unsigned char)fmin(obj_color.g * brightness, 255);
	output_color.b = (unsigned char)fmin(obj_color.b * brightness, 255);
	return (output_color);
}

void	render_scene(t_info *info)
{
	int				x;
	int				y;
	double			u;
	double			v;
	double			t;
	double			brightness;
	t_ray			ray;
	t_pos3			intersection;
	t_vec3			normal;
	t_vec3			light_direction;
	t_rgb3			rgb_color;
	t_rgb3			ambient;
	t_rgb3			diffuse;
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
			if (intersect_sphere(ray, info->sp.pos, info->sp.diameter / 2.0, &t))
			{
				intersection = pos_add_vec(ray.origin, vec_scale(ray.direction, t));
				normal = vec_normalize(pos_sub(intersection, info->sp.pos));
				printf("normal length = %.2f\n", vec_len(normal));
				printf("normal = (%.2f, %.2f, %.2f)\n", normal.x, normal.y, normal.z);
				light_direction = vec_normalize(pos_sub(intersection, info->lights->value.pos));
				brightness = fmax(0, vec_dot(normal, light_direction));
				ambient = apply_light(info->amb.rgb, info->amb.intensity, 1.0);
				diffuse = apply_light(info->sp.rgb, info->lights->value.intensity, brightness);
				(void)ambient;
				(void)diffuse;
				// rgb_color.r = fmin(ambient.r + diffuse.r, 255);
				// rgb_color.g = fmin(ambient.g + diffuse.g, 255);
				// rgb_color.b = fmin(ambient.b + diffuse.b, 255);

				double r = (normal.x + 1) / 2 * 255;
				double g = (normal.y + 1) / 2 * 255;
				double b = (normal.z + 1) / 2 * 255;
				printf("Raw Color: R=%.2f, G=%.2f, B=%.2f\n", r, g, b);

				rgb_color.r = (unsigned char)r;
				rgb_color.g = (unsigned char)g;
				rgb_color.b = (unsigned char)b;
				printf("Normalized Color: R=%d, G=%d, B=%d\n", rgb_color.r, rgb_color.g, rgb_color.b);
				color = rgb_to_uint(rgb_color);
				// color = 0x00FF0000;
			}
			base = (unsigned char *)info->mlx.img.addr;
			dst
				= base + y * info->mlx.img.line_len
				+ x * (info->mlx.img.bpp / 8);
			*(unsigned int *)dst = color;
		}
	}
}
