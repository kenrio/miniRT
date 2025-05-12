/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:53:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/12 18:12:20 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	bool validate_rgb_single(int n);

bool validate_unit(double n)
{
	return (0.0 <= n && n <= 1.0);
}

bool validate_unit_range(double n)
{
	return (-1.0 <= n && n <= 1.0);
}

bool validate_rad(double n)
{
	return (0.0 <= n && n <= 180.0);
}

bool	validate_rgb(t_rgb3	rgb)
{
	if (!validate_rgb_single(rgb.r)
		|| !validate_rgb_single(rgb.g)
		|| !validate_rgb_single(rgb.r))
		return (false);
	return (true);
}

static	bool validate_rgb_single(int n)
{
	return (0 <= n && n <=255);
}
