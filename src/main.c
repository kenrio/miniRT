/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/14 20:41:42 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (perror("Argument is missing"), 1);
	if (init_info(&info, argv[1]) == false)
		return (1);
	
	print_info(&info);

	// ここまではOK
	//TODO 実行部分の実装
	render_scene(&info);
	mlx_put_image_to_window(info.mlx.ptr, info.mlx.win, info.mlx.img.ptr, 0, 0);

	// ここから下もOK
	mlx_handle_hook(&info);
	mlx_loop(info.mlx.ptr);
	return (0);
}
