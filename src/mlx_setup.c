/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:13:06 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 21:58:26 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// setup mlx 4 elements.
bool	mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title)
{
	// mlx_ptr
	m->ptr = mlx_init();
	if (!m->ptr)
		return (false);

	// mlx_window
	m->win = mlx_new_window(m->ptr, win_w, win_h, win_title);
	if (!m->win)
		return (mlx_destroy_display(m->ptr), free(m->ptr), false);

	// mlx_img_ptr
	m->img.ptr = mlx_new_image(m->ptr, win_w, win_h);
	if (!m->img.ptr)
	{
		mlx_destroy_window(m->ptr, m->win);
		mlx_destroy_display(m->ptr);
		free(m->ptr);
		return (false);
	}

	// mlx_img_address
	m->img.addr = \
		(int *)mlx_get_data_addr(m->img.ptr, &m->img.bpp, &m->img.line_len, &m->img.endian);
	return (true);
}

