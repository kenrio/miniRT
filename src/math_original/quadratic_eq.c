/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anya_stella <anya_stella@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:47:30 by keishii           #+#    #+#             */
/*   Updated: 2025/05/15 07:44:49 by anya_stella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_quad_discriminant(t_quad_eq *q)
{
	q->discriminant = q->b * q->b - 4 * q->a * q->c;
	return (q->discriminant);
}

void	solve_quad_eq(t_quad_eq *q)
{
	double	sqrt_discriminant;

	sqrt_discriminant = sqrt(q->discriminant);
	q->t1 = (-q->b - sqrt_discriminant) / (2 * q->a);
	q->t2 = (-q->b + sqrt_discriminant) / (2 * q->a);
}
