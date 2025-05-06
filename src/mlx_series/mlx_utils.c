/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:21:48 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/05 21:26:54 by tishihar         ###   ########.fr       */
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
		mlx_destroy_display(m->ptr);
	free(m->ptr);
}
