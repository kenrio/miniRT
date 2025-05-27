/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:12:29 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/27 16:41:49 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb3	modulate_rgb(t_rgb3	base, t_rgb3 color)
{
	base.r *= (double)color.r / 255.0;
	base.g *= (double)color.g / 255.0;
	base.b *= (double)color.b / 255.0;
	return (base);
}

t_rgb3	multi_rgb(t_rgb3 base, double magnification)
{
	base.r *= magnification;
	base.g *= magnification;
	base.b *= magnification;
	return (base);
}
