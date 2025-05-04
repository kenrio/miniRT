/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:30:58 by keishii           #+#    #+#             */
/*   Updated: 2025/05/04 14:40:11 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	void	*mlx;
	void	*win;
	void	*img;
	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WIN_W, WIN_H, "miniRT");
	img = mlx_new_image(mlx, WIN_W, WIN_H);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_hook(win, 17, 0, &close_window, mlx);
	mlx_key_hook(win, &check_key_input, mlx);
	mlx_loop(mlx);
	return (0);
}
