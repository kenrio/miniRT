/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/14 20:45:02 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_info_start(t_info *info);

bool	init_info(t_info *info, char *file_name)
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
	mlx_cleanup(&info->mlx);
	clean_light_nodes(info->lights);
	clean_obj_nodes(info->objs);
}

static void	set_info_start(t_info *info)
{
	ft_bzero(info, sizeof(t_info));
	info->is_init_success = true;
}
