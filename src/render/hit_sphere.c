/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:58:50 by keishii           #+#    #+#             */
/*   Updated: 2025/05/05 21:59:17 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sphere(t_ray r, t_vec3 center, double radius, double *t_out)
{
    t_vec3 oc = v_sub(r.orig, center);
    double a = v_dot(r.dir, r.dir);
    double b = 2 * v_dot(oc, r.dir);
    double c = v_dot(oc, oc) - radius*radius;
    double disc = b*b - 4*a*c;
    if (disc < 0) return false;
    double t = (-b - sqrt(disc)) / (2*a);
    if (t < 1e-4) t = (-b + sqrt(disc)) / (2*a);
    if (t < 1e-4) return false;
    *t_out = t;
    return (true);
}

