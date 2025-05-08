/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:53:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 21:07:27 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool validate_rgb(int n)
{
	return (0 <= n && n <=255);
}

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
