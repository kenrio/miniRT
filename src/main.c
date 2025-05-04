/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/04 17:09:06 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	return (1);
	// if (parse_rt(argv[1], &scene))
	// 	return (error("Invalid .rt file"));
	if (mlx_setup(&mlx, WIN_W, WIN_H, "miniRT"))
		return (1);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	mlx_hook(mlx.win, 17, 0, &close_window, &mlx);
	mlx_key_hook(mlx.win, &check_key_input, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
