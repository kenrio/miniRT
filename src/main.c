/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 22:11:49 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_info	info;
	

	if (argc != 2)
		return (perror("Argument is missing"), 1);
	if (init_project(&info, argv[1]) == false)
		return (1);
	// 実行
	// ここまではOK
	mlx_put_image_to_window(&info.mlx, info.mlx.win, info.mlx.img.ptr, 0, 0);


	mlx_handle_hook(&info);
	mlx_loop(&info.mlx);
	return (0);
}
