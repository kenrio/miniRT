/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:25:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/12 19:11:09 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	deal_cross(t_info *info);
static int	deal_key(int key, t_info *info);
static void	close_window(t_info *info);

// hook of window close.
void	mlx_handle_hook(t_info *info)
{
	mlx_hook(info->mlx.win, 17, 0, deal_cross, info);
	mlx_key_hook(info->mlx.win, deal_key, info);
}

static	int	deal_cross(t_info *info)
{
	clean_info(info);
	exit(0);
	return (0);
}

static	int	deal_key(int key, t_info *info)
{
	if (key == ESC)
		close_window(info);
	return (0);
}

static void	close_window(t_info *info)
{
	clean_info(info);
	exit(0);
}
