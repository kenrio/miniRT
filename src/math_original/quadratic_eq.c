/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:47:30 by keishii           #+#    #+#             */
/*   Updated: 2025/05/11 14:26:20 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_quad_discriminant(t_quad_eq *q)
{
	q->discriminant = q->b * q->b - 4 * q->a * q->c;
	return (q->discriminant);
}

bool	solve_quad_eq(t_quad_eq *q)
{
	double	sqrt_discriminant;

	if (q->discriminant < 0)
		return (false);
	sqrt_discriminant = sqrt(q->discriminant);
	q->t1 = (-q->b - sqrt_discriminant) / (2 * q->a);
	q->t2 = (-q->b + sqrt_discriminant) / (2 * q->a);
	return (true);
}
