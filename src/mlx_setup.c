/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:13:06 by keishii           #+#    #+#             */
/*   Updated: 2025/05/04 16:45:52 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title)
{
	m->ptr = mlx_init();
	if (!m->ptr)
		return (1);
	m->win = mlx_new_window(m->ptr, win_w, win_h, win_title);
	if (!m->win)
		return (mlx_destroy_display(m->ptr), free(m->ptr), 1);
	m->img.ptr = mlx_new_image(m->ptr, win_w, win_h);
	if (!m->img.ptr)
		return (mlx_destroy_window(m->ptr, m->win),
			mlx_destroy_display(m->ptr),
			free(m->ptr), 1);
	m->img.addr = mlx_get_data_addr(m->img.ptr, &m->img.bpp, &m->img.line_len,
			&m->img.endian);
	m->img.w = win_w;
	m->img.h = win_h;
	return (0);
}
