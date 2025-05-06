/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/06 20:06:32 by keishii          ###   ########.fr       */
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
	// ここまではOK
	//TODO 実行部分の実装
	info.cam.pos = (t_pos3){0.0, 0.0, 0.0};
	info.cam.forward = (t_vec3){0.0, 0.0, 1.0};
	info.cam.fov = 70.0;
	cam_setup(&info.cam);
	render_scene(&info.mlx.img, &info.cam);
	mlx_put_image_to_window(info.mlx.ptr, info.mlx.win, info.mlx.img.ptr, 0, 0);
	// ここから下もOK
	mlx_handle_hook(&info);
	mlx_loop(info.mlx.ptr);
	return (0);
}
