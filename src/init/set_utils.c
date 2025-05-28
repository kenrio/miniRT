/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:47:12 by tishihar          #+#    #+#             */
/*   Updated: 2025/05/28 15:21:33 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	parse_double(char *token)
{
	if (!token)
		return (0.0);
	return (ft_atof(token));
}

// 255, shn255, 255
int	parse_3int(char *token, int idx)
{
	if (!token)
		return (0);
	while (*token && idx > 0)
	{
		while (*token && !(*token == ','))
			token++;
		while (*token == ',')
			token++;
		idx--;
	}
	if (is_valid_start(*token) == false)
	{
		perror("invalid input. 3 integer demand.");
		return (0);
	}
	return (ft_atoi(token));
}

double	parse_3double(char *token, int idx)
{
	if (!token)
		return (0.0);
	while (*token && idx > 0)
	{
		while (*token && !(*token == ','))
			token++;
		while (*token == ',')
			token++;
		idx--;
	}
	if (is_valid_start(*token) == false)
	{
		perror("invalid input. 3 double demand.");
		return (0.0);
	}
	return (ft_atof(token));
}

t_mat	parse_material(char *token)
{
	int		mat_number;
	t_mat	output;

	if (!token)
		output = MAT_NONE;
	mat_number = ft_atoi(token);
	if (mat_number == 1)
		output = MAT_DIFFUSE;
	else if (mat_number == 2)
		output = MAT_MIRROR;
	else if (mat_number == 3)
		output = MAT_METAL;
	else if (mat_number == 4)
		output = MAT_GLASS;
	else
		output = MAT_NONE;
	if (output == MAT_NONE)
		perror("mat type wrong.");
	return (output);
}
