/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:09:16 by keishii           #+#    #+#             */
/*   Updated: 2025/05/15 05:50:37 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	rgb_to_uint(t_rgb3 color)
{
	return (
		color.r << 16 | color.g << 8 | color.b
	);
}
