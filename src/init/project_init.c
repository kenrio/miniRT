/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/06 20:08:13 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool init_project(t_info *info, char *file_name)
{
	// ヌル初期化
	ft_bzero(info, sizeof(t_info));

	(void)file_name;
	// 初期化
	if (mlx_setup(&info->mlx, WIN_W, WIN_H, "miniRT") == false)
		return (perror("mlx setup failed."), false);

	// if (set_info(info, file_name) == false)
	// {
	// 	perror("init info failed.");
	// 	mlx_cleanup(&info->mlx);
	// 	return (false);
	// }

	return (true);
}

void	destroy_project(t_info *info)
{
	// mlxの開放
	mlx_cleanup(&info->mlx);
}
