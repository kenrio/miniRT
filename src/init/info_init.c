/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:45:46 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/06 14:46:05 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_info(t_info *info, char *file_name)
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
