/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 22:00:47 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "mlx.h"


//  --- macro ---
# define WIN_W 1024
# define WIN_H 1024
# define ESC 65307

//  --- structure ---
typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_info
{
	t_mlx	mlx;
}	t_info;

// ---functions---
// init
bool init_project(t_info *info, char *file_name);
void	destroy_project(t_info *info);



// mlx
bool	mlx_setup(t_mlx *m, int win_w, int win_h, char *win_title);
void	mlx_cleanup(t_mlx *m);
void	mlx_handle_hook(t_info *info);

#endif
