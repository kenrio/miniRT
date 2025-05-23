/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:16:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 20:35:33 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minirt.h"

 t_rgb3	add_rgb(t_rgb3 c1, t_rgb3 c2)
 {
	int r;
	int g;
	int b;

	r = fmin(c1.r + c2.r, 255);
	g = fmin(c1.g + c2.g, 255);
	b = fmin(c1.b + c2.b, 255);
	return ((t_rgb3){r, g, b});
 }
 
 // TODO理解する
 unsigned int	rgb_to_uint(t_rgb3 color)
{
	return (
		color.r << 16 | color.g << 8 | color.b
	);
}

t_rgb3	uint_to_rgb(unsigned int color_hex)
{
	t_rgb3	rgb;

	rgb.r = (color_hex >> 16) & 0xFF;
	rgb.g = (color_hex >> 8) & 0xFF;
	rgb.b = color_hex & 0xFF;
	return (rgb);
}
