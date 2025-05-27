/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:13:06 by keishii           #+#    #+#             */
/*   Updated: 2025/05/27 16:46:53 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// setup mlx 4 elements.
bool	init_mlx(t_mlx *m, int win_w, int win_h, char *win_title)
{
	m->ptr = mlx_init();
	if (!m->ptr)
		return (false);
	m->win = mlx_new_window(m->ptr, win_w, win_h, win_title);
	if (!m->win)
		return (mlx_destroy_display(m->ptr), free(m->ptr), false);
	m->img.ptr = mlx_new_image(m->ptr, win_w, win_h);
	if (!m->img.ptr)
	{
		mlx_destroy_window(m->ptr, m->win);
		mlx_destroy_display(m->ptr);
		return (free(m->ptr), false);
	}
	m->img.addr = (int *)mlx_get_data_addr(
			m->img.ptr, &m->img.bpp, &m->img.line_len, &m->img.endian);
	if (!m->img.addr)
	{
		mlx_destroy_image(m->ptr, m->img.ptr);
		mlx_destroy_window(m->ptr, m->win);
		mlx_destroy_display(m->ptr);
		return (free(m->ptr), false);
	}
	return (true);
}
