/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:30:40 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/23 18:30:56 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	apply_light(t_rgb3 color, double intensity, double dot_nl)
{
	t_rgb3	output_color;
	double	brightness;

	brightness = intensity * fmax(0, dot_nl);
	output_color.r = fmin(color.r * brightness, 255);
	output_color.g = fmin(color.g * brightness, 255);
	output_color.b = fmin(color.b * brightness, 255);
	return (output_color);
}
