/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cam_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:32:52 by keishii           #+#    #+#             */
/*   Updated: 2025/05/11 11:39:04 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_cam_info(t_cam *c)
{
	printf("Camera info: \n \
cam.pos:     (x: %.2lf, y: %.2lf, z: %.2lf)\n \
cam.forward: (x: %.2lf, y: %.2lf, z: %.2lf)\n \
cam.fov:     %.2lf degree\n \
cam.right:   (x: %.2lf, y: %.2lf, z: %.2lf)\n \
cam.up:      (x: %.2lf, y: %.2lf, z: %.2lf)\n \
cam.aspect:  %.2lf\n \
cam.half_h:  %.2lf\n \
cam.half_w:  %.2lf\n \
cam.llc:     (x: %.2lf, y: %.2lf, z: %.2lf)\n",
		c->pos.x, c->pos.y, c->pos.z,
		c->forward.x, c->forward.y, c->forward.z,
		c->fov,
		c->right.x, c->right.y, c->right.z,
		c->up.x, c->up.y, c->up.z,
		c->aspect,
		c->half_h,
		c->half_w,
		c->llc.x, c->llc.y, c->llc.z);
}
