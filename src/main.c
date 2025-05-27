/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/27 17:00:50 by keishii          ###   ########.fr       */
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
	render_scene(&info);
	mlx_put_image_to_window(info.mlx.ptr, info.mlx.win, info.mlx.img.ptr, 0, 0);
	mlx_handle_hook(&info);
	mlx_loop(info.mlx.ptr);
	return (0);
}
