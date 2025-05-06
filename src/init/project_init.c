/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/06 15:35:05 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool init_project(t_info *info, char *file_name)
{
	// ヌル初期化
	ft_bzero(info, sizeof(t_info));

	// 初期化
	if (mlx_setup(&info->mlx, WIN_W, WIN_H, "miniRT") == false)
		return (perror("mlx setup failed."), false);
	if (set_info(info, file_name) == false)
	{
		perror("init info failed.");
		mlx_cleanup(&info->mlx);
		return (false);
	}
	return (true);
}

void	destroy_project(t_info *info)
{
	// mlxの開放
	mlx_cleanup(&info->mlx);
}
