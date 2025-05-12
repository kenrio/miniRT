/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/12 18:00:22 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_info_start(t_info *info);

bool init_info(t_info *info, char *file_name)
{
	set_info_start(info);
	if (init_mlx(&info->mlx, WIN_W, WIN_H, "miniRT") == false)
		return (perror("initialization mlx failed."), false);
	if (init_elements(info, file_name) == false)
		return (clean_info(info), false);
	return (true);
}

void	clean_info(t_info *info)
{
	// mlxの開放
	mlx_cleanup(&info->mlx);

	// lights
	clean_light_nodes(info->lights);
}

static void	set_info_start(t_info *info)
{
	ft_bzero(info, sizeof(t_info));
	info->is_init_success = true;
}
