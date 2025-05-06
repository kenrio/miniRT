/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:45:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/06 15:37:30 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_info(t_info *info, char *file_name)
{
	int		file_fd;

	(void) info;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (false);
		
	// セットアップ

	
	if (set_amb(info) == false)
		return (close(file_fd), false);
	if (set_cam(info) == false)
		return (close(file_fd), false);
	if (set_light() == false)
		return (close(file_fd), false);
	// ここまで
	close(file_fd);
	return (true);
}
