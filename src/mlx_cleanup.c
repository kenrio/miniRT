/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:01:39 by keishii           #+#    #+#             */
/*   Updated: 2025/05/04 17:03:36 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_cleanup(t_mlx *m)
{
	if (m->img.ptr)
		mlx_destroy_image(m->ptr, m->img.ptr);
	if (m->win)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr)
	{
		mlx_destroy_display(m->ptr);
		free(m->ptr);
	}
}
