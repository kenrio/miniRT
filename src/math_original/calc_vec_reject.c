/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vec_reject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:10:46 by anya_stella       #+#    #+#             */
/*   Updated: 2025/05/15 23:18:15 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_reject(t_vec3 v, t_vec3 axis_unit)
{
	return (vec_sub(v, vec_scale(axis_unit, vec_dot(v, axis_unit))));
}
