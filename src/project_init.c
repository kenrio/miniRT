/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/06 14:30:25 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	bool	init_info(t_info *info, char *file_name);

bool init_project(t_info *info, char *file_name)
{
	if (mlx_setup(&info->mlx, WIN_W, WIN_H, "miniRT") == false)
		return (perror("mlx setup failed."), false);
	if (init_info(info, file_name) == false)
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

static	bool	init_info(t_info *info, char *file_name)
{
	int		file_fd;

	(void) info;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (false);

	// ここにファイルから読み取った内容をかきこむ

	close(file_fd);
	return (true);
}
