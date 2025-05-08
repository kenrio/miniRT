/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:28:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/08 20:13:29 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool init_info(t_info *info, char *file_name)
{
	ft_bzero(info, sizeof(t_info));
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

void	clean_info(t_info *info)
{
	// mlxの開放
	mlx_cleanup(&info->mlx);
}
