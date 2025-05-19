/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 05:07:05 by anya_stella       #+#    #+#             */
/*   Updated: 2025/05/19 13:20:41 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(int x, int y, unsigned int color, t_img *img)
{
	unsigned char	*base;
	unsigned char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	base = (unsigned char *)img->addr;
	dst = base + y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}
