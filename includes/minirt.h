/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:29:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/04 15:10:41 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>

# include "mlx.h"

# define WIN_W 1024
# define WIN_H 1024

# define ESC 65307

int	check_key_input(int key);
int	close_window(void);

#endif
